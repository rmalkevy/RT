/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/03 11:12:41 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_color			get_hyperbol_color(void *data)
{
	return (((t_hyperbol*)data)->details.col);
}

t_coefficients	get_hyperbol_coefficients(void *data)
{
	return (((t_hyperbol*)data)->details.coefficients);
}

t_vector		get_hyperbol_normal(void *data, t_vector ipoint)
{
	t_hyperbol	*hyperbol;
	t_vector	normal;

	hyperbol = (t_hyperbol *)data;
	normal.x = 2 * (2 * hyperbol->q.q1.x * ipoint.x + hyperbol->q.q3.x);
	normal.y = 2 * (2 * hyperbol->q.q1.y * ipoint.y + hyperbol->q.q3.y);
	normal.z = 2 * (2 * hyperbol->q.q1.z * ipoint.z + hyperbol->q.q3.z);
	vector_unit(&normal, &normal);
	return (normal);
}

int				intersects_hyperbol(void *data, t_vector *origin,
									t_vector *dir, double *t)
{
	t_hyperbol	*hyperbol;
	double		a;
	double		b;
	double		c;

	hyperbol = (t_hyperbol *)data;
	quadric_calculations(*origin, *dir, &hyperbol->q);
	quadric_get_abc(&a, &b, &c, &hyperbol->q);
	*t = discriminant(a, b, c);
	return ((*t > 0) ? TRUE : FALSE);
}

void			set_hyper_params(void *p)
{
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	ray->normal = ray->intersection_object->get_normal(
				ray->intersection_object->data, ray->intersection_point);
	ray->colors.ambient_color = ray->intersection_object->get_point_color(
												ray->intersection_object->data);
}
