/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 14:33:03 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 10:57:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_destination_point(t_params *par, int x, int y)
{
	t_vector	result;
	t_vector	x_dir_full;
	t_vector	y_dir_full;

	vector_mult(&par->camera.direction, par->camera.distance, &result);
	vector_sum(&par->camera.position.origin, &result, &result);
	vector_mult(&par->camera.x_dir, x - (par->width / 2), &x_dir_full);
	vector_mult(&par->camera.y_dir, y - (par->height / 2), &y_dir_full);
	vector_sum(&result, &x_dir_full, &result);
	vector_sum(&result, &y_dir_full, &result);
	return (result);
}

t_vector		get_direction(t_vector origin, t_vector dest)
{
	t_vector	res;

	vector_sub(&dest, &origin, &res);
	vector_unit(&res, &res);
	return (res);
}

t_ray_colors	init_ray_colors(void)
{
	t_ray_colors	res;

	res.ambient_color = new_color(0, 0, 0, 0);
	res.reflection_color = new_color(0, 0, 0, 0);
	res.refraction_color = new_color(0, 0, 0, 0);
	return (res);
}

t_ray_segment	new_ray_segment(t_vector start, t_vector dir)
{
	t_ray_segment	result;

	result.origin = start;
	result.direction = dir;
	result.colors = init_ray_colors();
	result.length = 0;
	result.refrect.refr_prev = 1;
	result.refrect.refr_curr = 1;
	result.intersection_point = new_vector_stack(0, 0, 0);
	result.refl_dir = new_vector_stack(0, 0, 0);
	result.refr_dir = new_vector_stack(0, 0, 0);
	result.intersection_object = NULL;
	result.ray_inside_object = 0;
	return (result);
}

t_ray			*new_ray(void)
{
	t_ray	*res;

	res = (t_ray*)malloc(sizeof(t_ray));
	res->refr_depth = 0;
	res->refl_depth = 0;
	res->len = 0;
	res->refracted = NULL;
	refr_lst__add_elem(&res->refracted, 0, 1.0);
	res->l_intens = NULL;
	res->final = new_color(0, 0, 0, 0);
	return (res);
}
