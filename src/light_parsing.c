/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:04:18 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 12:15:02 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					color_set_num(t_color *col, int red, int green,
																	int blue)
{
	col->red = red;
	col->green = green;
	col->blue = blue;
	col->op = 0;
}

void					set_light_init(t_l_params *par)
{
	color_set_num(&(par->color), 255, 255, 255);
	par->intensity = 1.0;
	par->decrement = 0;
}

t_parallel_light		*parse_parallel_light(char *str)
{
	t_parallel_light	*parallel_l;

	if (!(parallel_l = (t_parallel_light *)malloc(sizeof(t_parallel_light ))))
		error(errno);
	set_light_init(&(parallel_l->params));
	vector_set(0, 0, 1, &(parallel_l->direction));
	vector_set(0, 0, 0, &(parallel_l->rotation));
	fill_par_light(parallel_l, str);
	return (parallel_l);
}

t_light_point			*parse_light_point(char *str)
{
	t_light_point	*light_point;

	if (!(light_point = (t_light_point *)malloc(sizeof(t_light_point ))))
		error(errno);
	set_light_init(&(light_point->params));
	set_position(&(light_point->position));
	fill_light_point(light_point, str);
	return (light_point);
}

t_direct_light			*parse_light_dir(char *str)
{
	t_direct_light	*direct_light;

	if (!(direct_light = (t_direct_light *)malloc(sizeof(t_direct_light ))))
		error(errno);
	set_light_init(&(direct_light->params));
	set_position(&(direct_light->position));
	vector_set(0, 0, 1, &direct_light->direction);
	direct_light->angle = 30;
	fill_dir_light(direct_light, str);
	return (direct_light);
}
