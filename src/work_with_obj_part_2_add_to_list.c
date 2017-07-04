/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_obj_part_2_add_to_list.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/05 17:27:00 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	zoom_triangle(t_vector *a, t_vector *b, t_vector *c, double zoom)
{
	a->x = a->x * zoom;
	a->y = a->y * zoom;
	a->z = a->z * zoom;
	b->x = b->x * zoom;
	b->y = b->y * zoom;
	b->z = b->z * zoom;
	c->x = c->x * zoom;
	c->y = c->y * zoom;
	c->z = c->z * zoom;
}

void	add_triangle_to_list(t_params *par, double **vertices,
							int *faces, t_common com)
{
	t_triangle	*triangle;
	t_object	*obj;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		error(errno);
	triangle->details = com;
	triangle->a.x = vertices[faces[0] - 1][0];
	triangle->a.y = vertices[faces[0] - 1][1];
	triangle->a.z = vertices[faces[0] - 1][2];
	triangle->b.x = vertices[faces[1] - 1][0];
	triangle->b.y = vertices[faces[1] - 1][1];
	triangle->b.z = vertices[faces[1] - 1][2];
	triangle->c.x = vertices[faces[2] - 1][0];
	triangle->c.y = vertices[faces[2] - 1][1];
	triangle->c.z = vertices[faces[2] - 1][2];
	zoom_triangle(&triangle->a, &triangle->b, &triangle->c, com.zoom);
	obj = new_triangle(triangle, par->objects_qnt);
	object_add(&(par->objects), &obj);
	par->objects_qnt++;
}

char	*read_obj(char *file)
{
	t_read		parse;

	ft_bzero(parse.buf, BS + 1);
	parse.str = ft_strnew(0);
	if (((parse.fd = open(file, O_RDONLY)) < 0))
		error(errno);
	while ((parse.r = read(parse.fd, parse.buf, BS)))
	{
		if (parse.r == -1)
			error(errno);
		parse.tmp = parse.str;
		parse.str = ft_strjoin(parse.str, parse.buf);
		ft_bzero(parse.buf, BS + 1);
		free(parse.tmp);
	}
	close(parse.fd);
	return (parse.str);
}

void	work_with_obj(t_params *p, char *dots)
{
	t_triangle	*triangle;
	char		**split;
	int			i;

	i = -1;
	triangle = parse_triangle(dots);
	split = ft_strsplit(triangle->details.has_obj, '\n');
	parse_obj(split, p, triangle->details);
	while (split[++i])
	{
		free(split[i]);
		(split[i]) = NULL;
	}
	free(split);
	split = NULL;
	free(triangle->details.has_obj);
	free(triangle);
}
