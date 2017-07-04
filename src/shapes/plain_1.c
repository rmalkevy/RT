/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:55:14 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/01 13:56:13 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_coefficients	get_plain_coefficients(void *data)
{
	return (((t_plain*)data)->details.coefficients);
}

t_vector		get_plain_normal(void *data, t_vector ipoint)
{
	t_plain		*plain;

	(void)ipoint;
	plain = (t_plain *)data;
	return (plain->normal);
}

int				intersects_plain(void *data, t_vector *origin,
												t_vector *direction, double *t)
{
	t_plain		*plain;
	double		a;
	double		b;
	double		c;

	plain = (t_plain *)data;
	vector_dot(&plain->normal, direction, &a);
	vector_dot(&plain->normal, origin, &b);
	vector_dot(&plain->details.pos.origin, &plain->normal, &c);
	*t = (fabs(a) > 0.001) ? (-(b - c) / a) : -1;
	return ((*t > 0) ? TRUE : FALSE);
}
