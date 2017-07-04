/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:18:21 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 22:36:06 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	find_t(t_triangle *triangle, t_vector *dir, t_vector *origin)
{
	t_vector	ttt;
	double		u;
	double		v;
	t_vector	q;
	double		t;

	vector_cross(dir, &triangle->edge2, &triangle->p);
	vector_dot(&triangle->edge1, &triangle->p, &triangle->det);
	if (triangle->det < 0)
		return (0);
	if (fabs(triangle->det) < 0.00000001)
		return (0);
	triangle->inv_det = 1 / triangle->det;
	vector_sub(origin, &triangle->a, &ttt);
	vector_dot(&ttt, &triangle->p, &u);
	u = u * triangle->inv_det;
	if (u < 0 || u > 1)
		return (0);
	vector_cross(&ttt, &triangle->edge1, &q);
	vector_dot(dir, &q, &v);
	v = v * triangle->inv_det;
	if (v < 0 || u + v > 1)
		return (0);
	vector_dot(&triangle->edge2, &q, &t);
	return (t * triangle->inv_det);
}
