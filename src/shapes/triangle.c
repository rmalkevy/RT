/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/03 22:34:02 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			get_triangle_color(void *data)
{
	return (((t_triangle*)data)->details.col);
}

t_coefficients	get_triangle_coefficients(void *data)
{
	return (((t_triangle*)data)->details.coefficients);
}

t_vector		get_triangle_normal(void *data, t_vector ipoint)
{
	t_triangle	*triangle;

	(void)ipoint;
	triangle = (t_triangle *)data;
	return (triangle->normal);
}

/*
** Möller-Trumbore algorithm ray - triangle intersection
** Some calculations in -> void		rotate_triangle(void *data)
** vector_sub(&triangle->b, &triangle->a, &triangle->edge1);
** vector_sub(&triangle->c, &triangle->a, &triangle->edge2);
** vector_cross(&triangle->edge1, &triangle->edge2, &triangle->normal);
** vector_unit(&triangle->normal, &triangle->normal);
*/

int				intersects_triangle(void *data, t_vector *origin,
		t_vector *dir, double *t)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)data;
	*t = find_t(triangle, dir, origin);
	return ((*t > 0) ? TRUE : FALSE);
}

void			set_triangle_params(void *p)
{
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	ray->normal = ray->intersection_object->get_normal(
					ray->intersection_object->data, ray->intersection_point);
	ray->colors.ambient_color = ray->intersection_object->get_point_color(
												ray->intersection_object->data);
}
