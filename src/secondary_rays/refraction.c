/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:09:58 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 12:33:32 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		find_end_list(t_refr_lst **begin, t_refr_lst **end)
{
	*end = *begin;
	while ((*end)->next)
		*end = (*end)->next;
}

double		define_eff_refr(t_refr_lst **begin, t_refr_lst *current)
{
	t_refr_lst	*cursor;
	double		include_sum;
	double		delta_refr;

	cursor = *begin;
	include_sum = 0;
	delta_refr = 0;
	while (cursor != current->next)
	{
		cursor->include = cursor->refr_coeff - 1;
		include_sum += cursor->include;
		cursor = cursor->next;
	}
	cursor = *begin;
	if (include_sum == 0)
		include_sum = 1;
	while (cursor != current->next)
	{
		cursor->include = cursor->include / include_sum;
		delta_refr += cursor->include * (cursor->refr_coeff - 1);
		cursor = cursor->next;
	}
	return (1 + delta_refr);
}

void		define_prev_curr_refraction(t_refrect *refract, double refr_coeff,
							t_ray *ray_details, int id)
{
	t_refr_lst	*refr;
	t_refr_lst	*refr_prev;
	t_refr_lst	*end;

	if (!(refr = refr_lst__get_elem(&ray_details->refracted, id)))
	{
		refr_lst__add_elem(&ray_details->refracted, id, refr_coeff);
		refr = refr_lst__get_elem(&ray_details->refracted, id);
		refr_prev = (refr_lst__get_prev_elem(&ray_details->refracted, id));
		refract->refr_prev = define_eff_refr(&ray_details->refracted,
			refr_prev);
		refract->refr_curr = define_eff_refr(&ray_details->refracted, refr);
	}
	else
	{
		find_end_list(&ray_details->refracted, &end);
		refract->refr_prev = define_eff_refr(&ray_details->refracted, end);
		refr_lst__del_elem(&ray_details->refracted, id);
		find_end_list(&ray_details->refracted, &end);
		refract->refr_curr = define_eff_refr(&ray_details->refracted, end);
	}
}

int			define_refr_direction(t_vector *new_direction,
	t_vector *in_direction, t_vector *normal, t_refrect *refrect)
{
	double		c1;
	double		c2;
	double		n;
	t_vector	c1_norm;
	t_vector	acc;

	n = refrect->refr_prev / refrect->refr_curr;
	vector_dot(in_direction, normal, &c1);
	if ((c2 = (1 - n * n * (1 - c1 * c1))) >= 0)
		c2 = sqrt(c2);
	else
		return (0);
	acc = *in_direction;
	c1_norm = *normal;
	vector_mult(&c1_norm, (n * fabs(c1) - c2), &c1_norm);
	vector_mult(&acc, n, &acc);
	vector_sum(&c1_norm, &acc, new_direction);
	vector_unit(new_direction, new_direction);
	return (1);
	*new_direction = *in_direction;
}

t_vector	launch_refracted_ray(t_params *par, t_ray_segment ray,
							t_ray ray_details, t_color *color)
{
	t_vector		new_direction;
	t_ray_segment	refr_ray;

	define_prev_curr_refraction(&ray.refrect, ray.coefficients.refr_coeff,
		&ray_details, ray.intersection_object->id);
	check_light_side(&ray.normal, &ray.direction);
	if (!define_refr_direction(&new_direction, &ray.direction, &ray.normal,
		&ray.refrect))
	{
		*color = ray.colors.ambient_color;
		color->op = 200;
		return (new_vector_stack(0, 0, 0));
	}
	refr_ray = new_ray_segment(ray.intersection_point, new_direction);
	*color = cast_single_ray(par, refr_ray, ray_details);
	return (new_direction);
}
