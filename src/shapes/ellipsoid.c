/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/03 11:10:06 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_ellipse_color(void *data)
{
	return (((t_ellipsoid*)data)->details.col);
}

t_coefficients	get_ellipse_coefficients(void *data)
{
	return (((t_ellipsoid*)data)->details.coefficients);
}

t_vector		get_ellipse_normal(void *data, t_vector ipoint)
{
	t_ellipsoid	*ellipse;
	t_vector	normal;

	ellipse = (t_ellipsoid *)data;
	normal.x = 2 * (2 * ellipse->q.q1.x * ipoint.x + ellipse->q.q3.x);
	normal.y = 2 * (2 * ellipse->q.q1.y * ipoint.y + ellipse->q.q3.y);
	normal.z = 2 * (2 * ellipse->q.q1.z * ipoint.z + ellipse->q.q3.z);
	vector_unit(&normal, &normal);
	return (normal);
}

int				intersects_ellipse(void *data, t_vector *origin,
									t_vector *dir, double *t)
{
	t_ellipsoid		*ellipse;
	double			a;
	double			b;
	double			c;

	ellipse = (t_ellipsoid *)data;
	quadric_calculations(*origin, *dir, &ellipse->q);
	quadric_get_abc(&a, &b, &c, &ellipse->q);
	*t = discriminant(a, b, c);
	return ((*t > 0) ? TRUE : FALSE);
}

void			set_ellipse_params(void *p)
{
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	ray->normal = ray->intersection_object->get_normal(
					ray->intersection_object->data, ray->intersection_point);
	ray->colors.ambient_color = ray->intersection_object->get_point_color(
												ray->intersection_object->data);
}
