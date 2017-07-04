/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:32:42 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/04 20:24:41 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_coefficients	get_cylinder_coefficients(void *data)
{
	return (((t_cylinder*)data)->details.coefficients);
}

t_vector		get_cylinder_normal(void *data, t_vector ipoint)
{
	t_cylinder		*cylinder;
	t_compute		tmp;
	t_vector		normal;

	cylinder = (t_cylinder *)data;
	vector_sub(&ipoint, &cylinder->details.pos.origin, &tmp.v1);
	vector_dot(&tmp.v1, &cylinder->direction, &tmp.a);
	vector_mult(&cylinder->direction, tmp.a, &tmp.v2);
	vector_sum(&cylinder->details.pos.origin, &tmp.v2, &tmp.v2);
	vector_sub(&ipoint, &tmp.v2, &normal);
	vector_unit(&normal, &normal);
	return (normal);
}

void			cylinder_get_abc(double *a, double *b,
													double *c, t_compute *tmp)
{
	double e;
	double f;
	double g;

	vector_dot(&tmp->v2, &tmp->v2, &e);
	vector_dot(&tmp->v2, &tmp->v5, &f);
	vector_dot(&tmp->v5, &tmp->v5, &g);
	*a = e;
	*b = 2 * f;
	*c = g - tmp->g;
}

void			cylinder_common_calculations(t_cylinder *cylinder,
						t_vector *origin, t_vector *direction, t_compute *tmp)
{
	vector_dot(direction, &cylinder->direction, &tmp->a);
	vector_mult(&cylinder->direction, tmp->a, &tmp->v1);
	vector_sub(direction, &tmp->v1, &tmp->v2);
	vector_sub(origin, &cylinder->details.pos.origin, &tmp->v3);
	vector_dot(&tmp->v3, &cylinder->direction, &tmp->e);
	vector_mult(&cylinder->direction, tmp->e, &tmp->v4);
	vector_sub(&tmp->v3, &tmp->v4, &tmp->v5);
	tmp->g = cylinder->radius * cylinder->radius;
}

int				intersects_cylinder(void *data, t_vector *origin,
												t_vector *direction, double *t)
{
	t_cylinder		*cylinder;
	t_compute		tmp;
	double			a;
	double			b;
	double			c;

	cylinder = (t_cylinder *)data;
	cylinder_common_calculations(cylinder, origin, direction, &tmp);
	cylinder_get_abc(&a, &b, &c, &tmp);
	*t = discriminant(a, b, c);
	return ((*t > 0) ? TRUE : FALSE);
}
