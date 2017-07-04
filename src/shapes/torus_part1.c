/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_color			get_torus_color(void *data)
{
	return (((t_torus*)data)->details.col);
}

t_coefficients	get_torus_coefficients(void *data)
{
	return (((t_torus*)data)->details.coefficients);
}

t_vector		normal_x(t_torus *torus, t_vector center_to_point)
{
	double		y;
	t_vector	dd;
	t_vector	vec_axis;
	double		dot;
	t_vector	x;

	vector_dot(&torus->direction, &center_to_point, &y);
	vector_mult(&torus->direction, y, &vec_axis);
	vector_sub(&center_to_point, &vec_axis, &dd);
	vector_dot(&dd, &dd, &dot);
	dot = 1 / sqrt(dot) * torus->outer_radius;
	vector_mult(&dd, dot, &x);
	return (x);
}

t_vector		get_torus_normal(void *data, t_vector ipoint)
{
	t_torus		*torus;
	t_vector	center_to_point;
	t_vector	normal;
	t_vector	x;

	torus = (t_torus *)data;
	vector_sub(&ipoint, &torus->details.pos.origin, &center_to_point);
	x = normal_x(torus, center_to_point);
	vector_sub(&center_to_point, &x, &normal);
	vector_unit(&normal, &normal);
	return (normal);
}

int				intersects_torus(void *data, t_vector *orig,
									t_vector *dir, double *t)
{
	t_torus	*torus;
	double	tt[4];
	int		i;

	i = -1;
	while (++i < 4)
		tt[i] = -1;
	torus = (t_torus *)data;
	*t = find_t_torus(torus, dir, orig, tt);
	return ((*t > 0) ? TRUE : FALSE);
}
