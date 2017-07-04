/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:20:36 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 10:50:34 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		vector_magn(t_vector vec)
{
	return (fabs(sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)));
}

t_vector	unit_vector_stack(t_vector vec)
{
	double		magn;

	magn = vector_magn(vec);
	return (new_vector_stack(vec.x / magn, vec.y / magn, vec.z / magn));
}

t_vector	vector_sub_stack(t_vector v1, t_vector v2)
{
	return (new_vector_stack(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector	new_vector_stack(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
