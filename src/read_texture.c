/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:51:22 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:57 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		make_texture_map(t_texture *texture, int i, int j, int pos)
{
	texture->color = (t_color **)malloc(sizeof(t_color *) *
														(texture->height + 1));
	if (!texture->color)
		exit(0);
	while (i < texture->height)
	{
		j = 0;
		texture->color[i] = (t_color *)malloc(sizeof(t_color) *
														(texture->width + 1));
		if (!texture->color[i])
			exit(0);
		while (j < texture->width)
		{
			texture->color[i][j].blue = texture->data[pos++];
			texture->color[i][j].green = texture->data[pos++];
			texture->color[i][j].red = texture->data[pos++];
			texture->color[i][j].op = texture->data[pos++];
			j++;
		}
		i++;
	}
	texture->color[texture->height] = 0;
}

int			read_texture(char *filename, void *mlx, t_texture *texture)
{
	filename++;
	texture->ptr = mlx_xpm_file_to_image(mlx, filename,
										&texture->width, &texture->height);
	if (!texture->ptr)
	{
		ft_putendl("[Texture reading] File doesn't exist");
		return (FALSE);
	}
	texture->data = (unsigned char *)mlx_get_data_addr(texture->ptr,
						&texture->bbp, &texture->sizeline, &texture->end);
	if (!texture->data)
	{
		ft_putendl("[Texture reading] Memory error");
		return (FALSE);
	}
	make_texture_map(texture, 0, 0, 0);
	return (TRUE);
}
