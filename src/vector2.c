/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:16:31 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 10:51:28 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	translate_vector(t_vector cam, double x, double y, double z)
{
	t_vector	new;

	new = new_vector(cam.x + x, cam.y + y, cam.z + z);
	return (new);
}

double		vector_magn(t_vector vec)
{
	return (fabs(sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z)));
}

t_vector	add_vector(t_vector v1, t_vector v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector	vector_product(t_vector v1, t_vector v2)
{
	return (new_vector(v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x));
}
