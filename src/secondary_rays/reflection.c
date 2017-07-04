/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 10:58:12 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/30 19:17:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			define_refl_direction(t_vector *new_dir, t_vector prev_dir,
															t_vector normal)
{
	double		c1;
	t_vector	c1_norm;

	vector_dot(&prev_dir, &normal, &c1);
	c1 *= -1;
	c1_norm = normal;
	vector_mult(&c1_norm, 2 * c1, &c1_norm);
	vector_sum(&prev_dir, &c1_norm, new_dir);
	vector_unit(new_dir, new_dir);
}

t_shadow_ray	new_shadow_ray(t_shadow_ray *shadow_ray, t_object *object,
													t_vector new_dir, double t)
{
	t_shadow_ray	new_shadow_ray;

	new_shadow_ray.length = t;
	intersection_point(&shadow_ray->origin, &shadow_ray->direction,
							t, &new_shadow_ray.origin);
	new_shadow_ray.direction = new_dir;
	new_shadow_ray.normal = object->get_normal(object->data,
											new_shadow_ray.origin);
	new_shadow_ray.options = shadow_ray->options;
	new_shadow_ray.shading = shadow_ray->shading;
	new_shadow_ray.cos_phi = 0;
	new_shadow_ray.cos_teta = 0;
	new_shadow_ray.cur = shadow_ray->cur;
	new_shadow_ray.lgt_num = shadow_ray->lgt_num;
	new_shadow_ray.refr_cos = 1;
	new_shadow_ray.refl_cos = 1;
	new_shadow_ray.cos_coeff = 0;
	new_shadow_ray.exit = 0;
	return (new_shadow_ray);
}

t_shadow_ray	create_refracted_shadow_ray(t_shadow_ray *shadow_ray,
								t_object *object, double t, t_ray *ray_details)
{
	t_vector		new_direction;
	t_shadow_ray	new_ray;
	t_coefficients	coeff;

	(void)ray_details;
	coeff = object->get_coefficients(object->data);
	check_light_side(&shadow_ray->normal, &shadow_ray->direction);
	define_prev_curr_refraction(&shadow_ray->refrect, shadow_ray->refr_coeff,
													ray_details, object->id);
	if (!define_refr_direction(&new_direction, &shadow_ray->direction,
									&shadow_ray->normal, &shadow_ray->refrect))
	{
		new_ray.exit = 1;
		return (new_ray);
	}
	new_ray = new_shadow_ray(shadow_ray, object, new_direction, t);
	new_ray.refr = coeff.trans;
	new_ray.refr_coeff = shadow_ray->refrect.refr_prev;
	new_ray.refl = coeff.refl;
	new_ray.shading = 0;
	return (new_ray);
}

t_shadow_ray	create_reflected_shadow_ray(t_shadow_ray *shadow_ray,
					t_object *object, double t, t_ray *ray_details)
{
	t_vector		new_direction;
	t_shadow_ray	new_ray;
	t_coefficients	coeff;

	(void)ray_details;
	coeff = object->get_coefficients(object->data);
	define_refl_direction(&new_direction, shadow_ray->direction,
													shadow_ray->normal);
	new_ray = new_shadow_ray(shadow_ray, object, new_direction, t);
	new_ray.refr = coeff.trans;
	new_ray.refl = coeff.refl;
	return (new_ray);
}

t_vector		launch_reflected_ray(t_params *par, t_ray_segment ray,
							t_ray ray_details, t_color *color)
{
	t_vector		new_direction;
	t_ray_segment	refl_ray;
	t_refr_lst		*new_refracted;
	t_refr_lst		*old_refracted;
	t_refr_lst		*end;

	new_refracted = NULL;
	define_refl_direction(&new_direction, ray.direction, ray.normal);
	refl_ray = new_ray_segment(ray.intersection_point, new_direction);
	new_refracted = refr_lst__copy_lst(&ray_details.refracted);
	find_end_list(&new_refracted, &end);
	old_refracted = ray_details.refracted;
	ray_details.refracted = new_refracted;
	*color = cast_single_ray(par, refl_ray, ray_details);
	clear_refracted(new_refracted);
	ray_details.refracted = old_refracted;
	return (new_direction);
}
