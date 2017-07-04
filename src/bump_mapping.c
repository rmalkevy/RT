/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:58:18 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/05 15:18:09 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_tangent_space(t_vector *normal,
										t_vector *tangent, t_vector *binormal)
{
	t_vector	prostitude;

	vector_set(normal->x + 0.85f, normal->y + 0.85f,
												normal->z + 0.85f, &prostitude);
	vector_unit(&prostitude, &prostitude);
	vector_cross(normal, &prostitude, binormal);
	vector_cross(normal, binormal, tangent);
	vector_unit(binormal, binormal);
	vector_unit(tangent, tangent);
}

t_vector	mult_matrix(t_vector t, t_vector b, t_vector n, t_vector light_dir)
{
	t_vector	result;

	result.x = ((t.x * light_dir.x) + (t.y * light_dir.y) +
														(t.z * light_dir.z));
	result.y = ((b.x * light_dir.x) + (b.y * light_dir.y) +
														(b.z * light_dir.z));
	result.z = ((n.x * light_dir.x) + (n.y * light_dir.y) +
														(n.z * light_dir.z));
	vector_unit(&result, &result);
	return (result);
}

void		bump_mapping(t_shadow_ray *shad_ray, t_ray_segment *seg_ray)
{
	t_vector	tangent;
	t_vector	binormal;
	t_vector	normal;

	seg_ray = (t_ray_segment *)seg_ray;
	normal = seg_ray->normal_map;
	init_tangent_space(&normal, &tangent, &binormal);
	shad_ray->direction = mult_matrix(tangent, binormal,
												normal, shad_ray->direction);
}
