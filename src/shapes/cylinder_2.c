/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:35:29 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 17:32:22 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	get_cylinder_normal_save(t_cylinder *cylinder,
											t_vector ipoint, t_vector *ppoint)
{
	t_compute		tmp;
	t_vector		normal;

	vector_sub(&ipoint, &cylinder->details.pos.origin, &tmp.v1);
	vector_dot(&tmp.v1, &cylinder->direction, &tmp.a);
	vector_mult(&cylinder->direction, tmp.a, &tmp.v2);
	*ppoint = tmp.v2;
	vector_sum(&cylinder->details.pos.origin, &tmp.v2, &tmp.v2);
	vector_sub(&ipoint, &tmp.v2, &normal);
	vector_unit(&normal, &normal);
	return (normal);
}

t_vector	get_cylinder_normal_map(t_cyl_map *cn, t_vector normal)
{
	double		u;
	double		v;
	t_vector	normal_map;

	cn->dir_i = normal;
	vector_cos(&cn->ppoint, &cn->cylinder->direction, &cn->cos_ppoint_cyldir);
	vector_mod(&cn->ppoint, &cn->len_v);
	u = (int)cn->len_v;
	vector_dot(&cn->cylinder->dir_x, &cn->dir_i, &cn->dot__dir_x_i);
	cn->theta = acos(cn->dot__dir_x_i) * cn->cylinder->radius;
	cn->theta = ((int)cn->theta % (cn->cylinder->details.normal_map.width));
	vector_cross(&cn->cylinder->direction, &cn->cylinder->dir_x,
				&cn->cross__dir_cyl_x);
	vector_dot(&cn->cross__dir_cyl_x, &cn->dir_i, &cn->dot__cross);
	v = (cn->dot__cross > 0) ? cn->theta :
					(cn->cylinder->details.normal_map.width - 1) - cn->theta;
	u = (int)round((int)u % (cn->cylinder->details.normal_map.height - 1));
	if (cn->cos_ppoint_cyldir < 0)
		u = (cn->cylinder->details.normal_map.height - 1) - u;
	normal_map = cn->cylinder->details.normal_map.normal[(int)u][(int)v];
	return (normal_map);
}

t_color		get_cylinder_texture(t_cyl_map *cn, t_vector normal)
{
	double		u;
	double		v;
	t_color		color;

	cn->dir_i = normal;
	vector_cos(&cn->ppoint, &cn->cylinder->direction, &cn->cos_ppoint_cyldir);
	vector_mod(&cn->ppoint, &cn->len_v);
	u = (int)cn->len_v;
	vector_dot(&cn->cylinder->dir_x, &cn->dir_i, &cn->dot__dir_x_i);
	cn->theta = acos(cn->dot__dir_x_i) * cn->cylinder->radius;
	cn->theta = ((int)cn->theta % (cn->cylinder->details.texture.width));
	vector_cross(&cn->cylinder->direction, &cn->cylinder->dir_x,
				&cn->cross__dir_cyl_x);
	vector_dot(&cn->cross__dir_cyl_x, &cn->dir_i, &cn->dot__cross);
	v = (cn->dot__cross > 0) ? cn->theta :
						(cn->cylinder->details.texture.width - 1) - cn->theta;
	u = (int)round((int)u % (cn->cylinder->details.texture.height - 1));
	if (cn->cos_ppoint_cyldir < 0)
		u = (cn->cylinder->details.texture.height - 1) - u;
	color = cn->cylinder->details.texture.color[(int)u][(int)v];
	return (color);
}

void		set_cylinder_params(void *p)
{
	t_ray_segment	*ray;
	t_cyl_map		cn;

	ray = (t_ray_segment *)p;
	cn.cylinder = (t_cylinder *)ray->intersection_object->data;
	ray->normal = get_cylinder_normal_save(cn.cylinder,
										ray->intersection_point, &cn.ppoint);
	if (cn.cylinder->details.has_texture)
		ray->colors.ambient_color = get_cylinder_texture(&cn, ray->normal);
	else
		ray->colors.ambient_color = cn.cylinder->details.col;
	if (cn.cylinder->details.has_normal_map)
	{
		ray->normal_map = get_cylinder_normal_map(&cn, ray->normal);
		ray->bump_mapping = TRUE;
	}
	else
		ray->bump_mapping = FALSE;
}
