/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:38:45 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 13:59:46 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_sphere_normal(void *data, t_vector ipoint)
{
	t_sphere	sphere;
	t_vector	normal;

	sphere = *(t_sphere *)data;
	vector_sub(&ipoint, &sphere.details.pos.origin, &normal);
	vector_unit(&normal, &normal);
	return (normal);
}

t_coefficients	get_sphere_coefficients(void *data)
{
	return (((t_sphere*)data)->details.coefficients);
}

double			dynamic_radius_sphere(int old_radius, int range)
{
	int new_radius;
	int value;

	if (range > 0)
	{
		value = rand();
		new_radius = (old_radius + value % range);
		return (new_radius);
	}
	return (old_radius);
}

int				intersects_sphere(void *data, t_vector *orig,
													t_vector *dir, double *t)
{
	t_sphere		*sphere;
	t_compute		tmp;
	int				radius;
	double			b;
	double			c;

	sphere = (t_sphere *)data;
	vector_sub(orig, &sphere->details.pos.origin, &tmp.v1);
	vector_dot(dir, &tmp.v1, &tmp.b);
	b = 2 * tmp.b;
	vector_mod(&tmp.v1, &tmp.a);
	radius = dynamic_radius_sphere(sphere->radius, 0);
	c = (tmp.a * tmp.a) - (radius * radius);
	*t = discriminant(1, b, c);
	return ((*t > 0) ? TRUE : FALSE);
}
