/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:16:43 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 13:49:17 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		get_cone_normal(void *data, t_vector ipoint)
{
	t_cone			*cone;
	t_compute		tmp;
	t_vector		normal;

	cone = (t_cone *)data;
	vector_sub(&ipoint, &cone->details.pos.origin, &tmp.v1);
	vector_dot(&tmp.v1, &cone->direction, &tmp.a);
	vector_mult(&cone->direction, tmp.a, &tmp.v2);
	vector_sum(&cone->details.pos.origin, &tmp.v2, &tmp.v2);
	vector_sub(&ipoint, &tmp.v2, &tmp.v2);
	vector_cross(&tmp.v2, &tmp.v1, &tmp.v3);
	vector_cross(&tmp.v1, &tmp.v3, &tmp.v4);
	vector_unit(&tmp.v4, &normal);
	return (normal);
}

t_coefficients	get_cone_coefficients(void *data)
{
	return (((t_cone*)data)->details.coefficients);
}

void			cone_get_abc(double *a, double *b, double *c, t_compute *tmp)
{
	double e;
	double f;
	double g;

	vector_dot(&tmp->v2, &tmp->v2, &e);
	vector_dot(&tmp->v2, &tmp->v5, &f);
	vector_dot(&tmp->v5, &tmp->v5, &g);
	*a = (tmp->cos * e) - (tmp->sin * (tmp->a * tmp->a));
	*b = ((2 * tmp->cos) * f) - ((2 * tmp->sin) * tmp->a * tmp->e);
	*c = (tmp->cos * g) - (tmp->sin * (tmp->e * tmp->e));
}

void			cone_common_calculations(t_cone *cone, t_vector origin,
											t_vector direction, t_compute *tmp)
{
	vector_dot(&direction, &cone->direction, &tmp->a);
	vector_mult(&cone->direction, tmp->a, &tmp->v1);
	vector_sub(&direction, &tmp->v1, &tmp->v2);
	vector_sub(&origin, &cone->details.pos.origin, &tmp->v3);
	vector_dot(&tmp->v3, &cone->direction, &tmp->e);
	vector_mult(&cone->direction, tmp->e, &tmp->v4);
	vector_sub(&tmp->v3, &tmp->v4, &tmp->v5);
	tmp->cos = cos(cone->angle * (M_PI / 180));
	tmp->sin = sin(cone->angle * (M_PI / 180));
	tmp->cos *= tmp->cos;
	tmp->sin *= tmp->sin;
}

int				intersects_cone(void *data, t_vector *origin,
													t_vector *dir, double *t)
{
	t_cone			*cone;
	t_compute		tmp;
	double			a;
	double			b;
	double			c;

	cone = (t_cone *)data;
	cone_common_calculations(cone, *origin, *dir, &tmp);
	cone_get_abc(&a, &b, &c, &tmp);
	*t = discriminant(a, b, c);
	return ((*t > 0) ? TRUE : FALSE);
}
