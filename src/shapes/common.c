/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:31:03 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/05 15:14:35 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			discriminant(double a, double b, double c)
{
	double		d;
	double		t1;
	double		t2;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	t1 = (-b + sqrt(d)) / (2 * a);
	t2 = (-b - sqrt(d)) / (2 * a);
	if (t1 <= t2 && t1 > EPSILON)
		return (t1);
	else if (t2 <= t1 && t2 > EPSILON)
		return (t2);
	else if (t1 >= t2 && t1 > EPSILON)
		return (t1);
	else if (t2 >= t1 && t2 > EPSILON)
		return (t2);
	return (-1);
}

t_color			get_cone_color(void *data)
{
	return (((t_cone*)data)->details.col);
}

t_color			get_cylinder_color(void *data)
{
	return (((t_cylinder*)data)->details.col);
}

t_color			get_plain_color(void *data)
{
	return (((t_plain*)data)->details.col);
}

t_color			get_sphere_color(void *data)
{
	return (((t_sphere*)data)->details.col);
}
