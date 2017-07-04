/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:32:15 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/15 19:15:21 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

t_vector	rotate_vec_single_axis(t_vector v, int axis, double ang)
{
	if (axis == X)
		return (new_vector_stack(v.x, v.y * cos(ang) + v.z * sin(ang),
					-v.y * sin(ang) + v.z * cos(ang)));
	else if (axis == Y)
		return (new_vector_stack(v.x * cos(ang) + v.z * sin(ang), v.y,
					-v.x * sin(ang) + v.z * cos(ang)));
	else if (axis == Z)
		return (new_vector_stack(v.x * cos(ang) + v.y * sin(ang),
					-v.x * sin(ang) + v.y * cos(ang), v.z));
	else
		return (v);
}

void		rotate_vector(t_vector *vec, double x, double y, double z)
{
	x *= (M_PI / 180.);
	y *= (M_PI / 180.);
	z *= (M_PI / 180.);
	*vec = rotate_vec_single_axis(
			rotate_vec_single_axis(
				rotate_vec_single_axis(
					*vec, X, x), Y, y), Z, z);
}

void		rotate_vector_by_vector(t_vector *vec, t_vector *rotation)
{
	rotate_vector(vec, rotation->x, rotation->y, rotation->z);
}

void		translate_vector(t_vector *vec, double x, double y, double z)
{
	vec->x += x;
	vec->y += y;
	vec->z += z;
}

void		translate_vector_by_vector(t_vector *vec, t_vector *transl)
{
	vec->x += transl->x;
	vec->y += transl->y;
	vec->z += transl->z;
}
