/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 19:19:26 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 16:05:48 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	get_cone_normal_save(void *data, t_vector ipoint,
											t_vector *ppoint, double *radius)
{
	t_cone			*cone;
	t_compute		tmp;
	t_vector		normal;

	cone = (t_cone *)data;
	vector_sub(&ipoint, &cone->details.pos.origin, &tmp.v1);
	vector_dot(&tmp.v1, &cone->direction, &tmp.a);
	vector_mult(&cone->direction, tmp.a, &tmp.v2);
	*ppoint = tmp.v2;
	vector_sum(&cone->details.pos.origin, &tmp.v2, &tmp.v2);
	vector_sub(&ipoint, &tmp.v2, &tmp.v2);
	vector_cross(&tmp.v2, &tmp.v1, &tmp.v3);
	vector_cross(&tmp.v1, &tmp.v3, &tmp.v4);
	vector_mod(&tmp.v2, radius);
	vector_unit(&tmp.v4, &normal);
	return (normal);
}

t_vector	get_cone_normal_map(t_co_map *cn, t_vector normal)
{
	double				v;
	double				u;
	t_vector			normal_map;

	vector_set(1, 0, 0, &cn->cone->dir_x);
	vector_cos(&cn->ppoint, &cn->cone->direction, &cn->cos_ppoint_condir);
	vector_mod(&cn->ppoint, &cn->len_v);
	cn->dir_i = normal;
	v = ((int)cn->len_v % cn->cone->details.normal_map.height);
	vector_dot(&cn->cone->dir_x, &cn->dir_i, &cn->dot__dir_x_i);
	cn->theta = acos(cn->dot__dir_x_i) * cn->radius;
	cn->theta = (int)cn->theta % cn->cone->details.normal_map.width;
	vector_cross(&cn->cone->direction, &cn->cone->dir_x, &cn->cross__dir_con_x);
	vector_dot(&cn->cross__dir_con_x, &cn->dir_i, &cn->dot__cross);
	u = (cn->dot__cross > 0) ? cn->theta :
						(cn->cone->details.normal_map.width - 1) - cn->theta;
	v = (cn->cos_ppoint_condir > 0) ? v :
								(cn->cone->details.normal_map.height - 1) - v;
	normal_map = cn->cone->details.normal_map.normal[(int)v][(int)u];
	return (normal_map);
}

t_color		get_cone_texture(t_co_map *cn, t_vector normal)
{
	double				v;
	double				u;
	t_color				color;

	vector_set(1, 0, 0, &cn->cone->dir_x);
	vector_cos(&cn->ppoint, &cn->cone->direction, &cn->cos_ppoint_condir);
	vector_mod(&cn->ppoint, &cn->len_v);
	cn->dir_i = normal;
	v = ((int)cn->len_v % cn->cone->details.texture.height);
	vector_dot(&cn->cone->dir_x, &cn->dir_i, &cn->dot__dir_x_i);
	cn->theta = acos(cn->dot__dir_x_i) * cn->radius;
	cn->theta = (int)cn->theta % cn->cone->details.texture.width;
	vector_cross(&cn->cone->direction, &cn->cone->dir_x, &cn->cross__dir_con_x);
	vector_dot(&cn->cross__dir_con_x, &cn->dir_i, &cn->dot__cross);
	u = (cn->dot__cross > 0) ? cn->theta :
							(cn->cone->details.texture.width - 1) - cn->theta;
	v = (cn->cos_ppoint_condir > 0) ? v :
									(cn->cone->details.texture.height - 1) - v;
	color = cn->cone->details.texture.color[(int)v][(int)u];
	return (color);
}

void		set_cone_params(void *p)
{
	t_ray_segment	*ray;
	t_co_map		cn;

	ray = (t_ray_segment *)p;
	cn.cone = (t_cone *)ray->intersection_object->data;
	ray->normal = get_cone_normal_save(cn.cone, ray->intersection_point,
														&cn.ppoint, &cn.radius);
	if (cn.cone->details.has_texture)
		ray->colors.ambient_color = get_cone_texture(&cn, ray->normal);
	else
		ray->colors.ambient_color = cn.cone->details.col;
	if (cn.cone->details.has_normal_map)
	{
		ray->normal_map = get_cone_normal_map(&cn, ray->normal);
		ray->bump_mapping = TRUE;
	}
	else
		ray->bump_mapping = FALSE;
}
