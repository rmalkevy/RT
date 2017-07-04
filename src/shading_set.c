/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:23:06 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 10:45:06 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			set_affine_vectors(t_plain *plain)
{
	t_vector	prostitude;

	vector_set(plain->normal.x + 0.15f, plain->normal.y + 0.15f,
										plain->normal.z + 0.15f, &prostitude);
	vector_unit(&prostitude, &prostitude);
	vector_cross(&prostitude, &plain->normal, &plain->dir_x);
	vector_cross(&plain->dir_x, &plain->normal, &plain->dir_y);
}

void			set_calculate_light(t_params *par, t_ray *ray_details,
										t_shadow_ray *shadow_ray)
{
	set_light_intensity(par, ray_details);
	(*ray_details).refr_depth = 0;
	(*ray_details).refl_depth = 0;
	(*ray_details).refracted = shadow_ray->refracted;
}

void			check_light_side(t_vector *normal, t_vector *ray_dir)
{
	double	cos_ray_normal;

	vector_dot(normal, ray_dir, &cos_ray_normal);
	if (cos_ray_normal > 0)
		vector_mult(normal, -1, normal);
}

void			shadow_ray_set_params(t_shadow_ray *ray,
					t_ray_segment ray_segment, t_refr_lst *refracted)
{
	ray->length = -1;
	vector_set(0, 0, 0, &ray->direction);
	ray->cos_phi = 0;
	ray->cos_teta = 0;
	ray->refr_cos = 1;
	ray->refl_cos = 1;
	ray->cos_coeff = 0;
	ray->refrect = ray_segment.refrect;
	ray->origin = ray_segment.intersection_point;
	ray->normal = ray_segment.normal;
	ray->refl_dir = ray_segment.refl_dir;
	ray->refr_dir = ray_segment.refr_dir;
	ray->refl = ray_segment.coefficients.refl;
	ray->refr = ray_segment.coefficients.refl;
	ray->amb = ray_segment.coefficients.amb;
	ray->refracted = refracted;
}

void			final_shadow_ray_set_params(t_shadow_ray *ray)
{
	ray->length = -1;
	vector_set(0, 0, 0, &ray->direction);
	ray->cos_phi = 0;
	ray->cos_teta = 0;
	ray->refr_cos = 1;
	ray->refl_cos = 1;
	ray->cos_coeff = 0;
}
