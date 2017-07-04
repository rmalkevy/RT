/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_normal_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:44:26 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/03 12:03:37 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		make_normal_map(t_normal_map *map, int i, int j, int pos)
{
	map->normal = (t_vector **)malloc(sizeof(t_vector *) * (map->height + 1));
	if (!map->normal)
		exit(0);
	while (i < map->height)
	{
		j = 0;
		map->normal[i] = (t_vector *)malloc(sizeof(t_vector) *
															(map->width + 1));
		if (!map->normal[i])
			exit(0);
		while (j < map->width)
		{
			map->normal[i][j].x = (((double)map->data[pos++]));
			map->normal[i][j].y = (((double)map->data[pos++]));
			map->normal[i][j].z = (((double)map->data[pos++]));
			vector_unit(&map->normal[i][j], &map->normal[i][j]);
			map->normal[i][j].x = (map->normal[i][j].x * 2) - 1;
			map->normal[i][j].y = (map->normal[i][j].y * 2) - 1;
			map->normal[i][j].z = (map->normal[i][j].z * 2) - 1;
			pos++;
			j++;
		}
		i++;
	}
	map->normal[map->height] = 0;
}

int			read_normal_map(char *filename, void *mlx, t_normal_map *normal)
{
	filename++;
	normal->ptr = mlx_xpm_file_to_image(mlx, filename,
						&normal->width, &normal->height);
	if (!normal->ptr)
	{
		ft_putendl("[Normal map reading] File doesn't exist");
		return (FALSE);
	}
	normal->data = (unsigned char *)mlx_get_data_addr(normal->ptr,
						&normal->bbp, &normal->sizeline, &normal->end);
	if (!normal->data)
	{
		ft_putendl("[Normal map reading] Memory error");
		return (FALSE);
	}
	make_normal_map(normal, 0, 0, 0);
	return (TRUE);
}
