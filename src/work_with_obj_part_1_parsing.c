/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_obj_part_1_parsing.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/05 17:36:18 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	parse_vertices(char *split, int *cntv, double **vertices)
{
	char **split_vertice;

	split_vertice = ft_strsplit(split + 1, ' ');
	vertices[(*cntv)][0] = ft_atof(split_vertice[0]);
	vertices[(*cntv)][1] = ft_atof(split_vertice[1]);
	vertices[(*cntv)][2] = ft_atof(split_vertice[2]);
	free(split_vertice[0]);
	free(split_vertice[1]);
	free(split_vertice[2]);
	free(split_vertice[3]);
	free(split_vertice);
	(*cntv)++;
}

void	parse_faces(char *split, int *cntf, int **faces)
{
	char **split_faces;

	split_faces = ft_strsplit(split + 1, ' ');
	faces[(*cntf)][0] = ft_atoi(split_faces[0]);
	faces[(*cntf)][1] = ft_atoi(split_faces[1]);
	faces[(*cntf)][2] = ft_atoi(split_faces[2]);
	free(split_faces[0]);
	free(split_faces[1]);
	free(split_faces[2]);
	free(split_faces);
	(*cntf)++;
}

void	malloc_poligons(t_common com, double **vertices, int **faces)
{
	int		i;

	i = -1;
	while (++i < com.num_poligon)
	{
		vertices[i] = (double*)malloc(sizeof(double) * 3);
		faces[i] = (int*)malloc(sizeof(int) * 3);
	}
}

void	free_vertices_and_faces(t_common com, double **vertices, int **faces)
{
	int i;

	i = -1;
	while (++i < com.num_poligon)
	{
		free(vertices[i]);
		free(faces[i]);
		vertices[i] = NULL;
		faces[i] = NULL;
	}
	free(vertices);
	free(faces);
	vertices = NULL;
	faces = NULL;
}

void	parse_obj(char **split, t_params *par, t_common com)
{
	int		i;
	int		cntv;
	int		cntf;
	double	**vertices;
	int		**faces;

	cntf = 0;
	cntv = 0;
	vertices = (double**)malloc(sizeof(double*) * com.num_poligon);
	faces = (int**)malloc(sizeof(int*) * com.num_poligon);
	malloc_poligons(com, vertices, faces);
	i = -1;
	while (split[++i])
	{
		if (split[i][0] == 'v' && split[i][1] != 'n' && split[i][1] != 't')
			parse_vertices(split[i], &cntv, vertices);
		else if (split[i][0] == 'f')
			parse_faces(split[i], &cntf, faces);
	}
	i = -1;
	while (++i < cntf)
		add_triangle_to_list(par, vertices, faces[i], com);
	free_vertices_and_faces(com, vertices, faces);
}
