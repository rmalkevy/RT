/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:19:43 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 15:13:49 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	calculate_light(t_params *par, t_shadow_ray *shadow_ray,
				t_ray_segment *ray_segment, t_shadow_ray *final_ray)
{
	double		t;
	t_object	*object;
	t_ray		ray_details;

	t = -1;
	define_cos_phi(&(shadow_ray->cos_phi), &(shadow_ray->normal),
						&(shadow_ray->direction), shadow_ray->shading);
	set_calculate_light(par, &ray_details, shadow_ray);
	if (shadow_ray->refl)
		define_cos_teta(&(shadow_ray->cos_teta), &(shadow_ray->refl_dir),
								&(shadow_ray->direction), shadow_ray->shading);
	shadow_ray->intersection_object = ray_segment->intersection_object;
	object = find_closest_intersection(par, &(shadow_ray->origin),
										&(shadow_ray->direction), &t);
	if (t != -1 && t < shadow_ray->length && t > EPSILON)
	{
		final_ray->cos_coeff = (1 - par->env.shades_present);
		shadow_ray->cos_phi = shadow_ray->cos_phi * final_ray->cos_coeff;
		shadow_ray->cos_teta = shadow_ray->cos_teta * final_ray->cos_coeff;
	}
	define_shade_and_glare(par, shadow_ray, ray_segment);
	free(ray_details.l_intens);
}

void	shade_pixel(t_params *par, t_ray_segment *ray_segment,
									t_ray *ray_details, t_refr_lst *refracted)
{
	t_light			*cur;
	t_shadow_ray	shadow_ray;
	t_shadow_ray	final_ray;
	int				i;

	cur = par->lights;
	shadow_ray_set_params(&shadow_ray, *ray_segment, refracted);
	final_shadow_ray_set_params(&final_ray);
	check_light_side(&shadow_ray.normal, &(ray_segment->direction));
	i = 0;
	while (cur)
	{
		cur->set_lighting_params(cur->source, &shadow_ray, ray_details, i++);
		if (ray_segment->bump_mapping)
			bump_mapping(&shadow_ray, ray_segment);
		shadow_ray.cur = cur;
		shadow_ray.lgt_num = i - 1;
		calculate_light(par, &shadow_ray, ray_segment, &final_ray);
		cur = cur->next;
	}
}
