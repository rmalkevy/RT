/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 21:44:22 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/04 19:57:57 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				disc_inters_in_radius(t_disc *disc, t_vector *inters)
{
	t_vector	origin_to_inters;
	double		dist;

	vector_sub(inters, &disc->details.pos.origin, &origin_to_inters);
	vector_mod(&origin_to_inters, &dist);
	if (dist > disc->radius)
		return (0);
	return (1);
}

int				intersects_disc(void *d, t_vector *orig, t_vector *dir,
		double *t)
{
	t_disc		*disc;
	double		abc[3];
	double		temp_t;
	t_vector	inters_point;

	disc = (t_disc*)d;
	vector_dot(&disc->normal, dir, &abc[0]);
	vector_dot(&disc->normal, orig, &abc[1]);
	vector_dot(&disc->details.pos.origin, &disc->normal, &abc[2]);
	temp_t = (fabs(abc[0]) > 0.001) ? (-(abc[1] - abc[2]) / abc[0]) : -1;
	vector_mult(dir, temp_t, &inters_point);
	vector_sum(&inters_point, orig, &inters_point);
	if (temp_t != -1 && disc_inters_in_radius(disc, &inters_point))
	{
		*t = temp_t;
		return (1);
	}
	return (0);
}

void			set_disc_params(void *p)
{
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	ray->normal = ray->intersection_object->get_normal(
			ray->intersection_object->data, ray->intersection_point);
	ray->colors.ambient_color = ray->intersection_object->get_point_color(
			ray->intersection_object->data);
}

t_object		*new_disc(t_disc *disc, int id)
{
	t_object	*res;

	if (!(res = (t_object*)malloc(sizeof(t_object))))
		error(errno);
	res->data = disc;
	res->name = ft_strdup("disc");
	res->intersects = intersects_disc;
	res->get_normal = get_disc_normal;
	res->get_point_color = get_disc_color;
	res->get_coefficients = get_disc_coefficients;
	res->move_object = move_disc;
	res->rotate_object = rotate_disc;
	res->set_params = set_disc_params;
	res->id = id;
	return (res);
}
