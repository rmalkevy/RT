/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:57:19 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/02 18:20:48 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_sphere_texture(t_sp_map *cn, t_vector normal)
{
	double		u;
	double		v;
	t_color		color;
	double		test;

	cn->dir_i = normal;
	vector_dot(&cn->sphere->dir_y, &cn->dir_i, &cn->dot_dir_y_dir_i);
	cn->phi = acos(-cn->dot_dir_y_dir_i);
	v = cn->phi / M_PI;
	vector_dot(&cn->sphere->dir_x, &cn->dir_i, &cn->dot_dir_x_dir_i);
	test = cn->dot_dir_x_dir_i / sin(cn->phi);
	if (abs((int)test) == 1)
		test += (test > 0) ? -0.0001 : 0.0001;
	cn->theta = acos(test) / (2 * M_PI);
	vector_cross(&cn->sphere->dir_y, &cn->sphere->dir_x,
				&cn->cross__dir_y__dir_x);
	vector_dot(&cn->cross__dir_y__dir_x, &cn->dir_i, &cn->dot__cross__dir_i);
	u = (cn->dot__cross__dir_i > 0) ? 1 - cn->theta : cn->theta;
	v = (int)round(v * (cn->sphere->details.texture.height - 1));
	u = (int)round(u * (cn->sphere->details.texture.width - 1));
	color = cn->sphere->details.texture.color[(int)v][(int)u];
	return (color);
}

t_vector	get_sphere_normal_map(t_sp_map *cn, t_vector normal)
{
	double		u;
	double		v;
	double		test;
	t_vector	normal_map;

	cn->dir_i = normal;
	vector_dot(&cn->sphere->dir_y, &cn->dir_i, &cn->dot_dir_y_dir_i);
	cn->phi = acos(-cn->dot_dir_y_dir_i);
	v = cn->phi / M_PI;
	vector_dot(&cn->sphere->dir_x, &cn->dir_i, &cn->dot_dir_x_dir_i);
	test = cn->dot_dir_x_dir_i / sin(cn->phi);
	if (abs((int)test) == 1)
		test += (test > 0) ? -0.0001 : 0.0001;
	cn->theta = acos(test) / (2 * M_PI);
	vector_cross(&cn->sphere->dir_y, &cn->sphere->dir_x,
				&cn->cross__dir_y__dir_x);
	vector_dot(&cn->cross__dir_y__dir_x, &cn->dir_i, &cn->dot__cross__dir_i);
	u = (cn->dot__cross__dir_i > 0) ? cn->theta : 1 - cn->theta;
	v = (int)round(v * (cn->sphere->details.normal_map.width - 1));
	u = (int)round(u * (cn->sphere->details.normal_map.height - 1));
	normal_map = cn->sphere->details.normal_map.normal[(int)v][(int)u];
	return (normal_map);
}

void		set_sphere_params(void *p)
{
	t_sp_map		cn;
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	cn.sphere = (t_sphere *)ray->intersection_object->data;
	ray->normal = get_sphere_normal(cn.sphere, ray->intersection_point);
	if (cn.sphere->details.has_texture)
		ray->colors.ambient_color = get_sphere_texture(&cn, ray->normal);
	else
		ray->colors.ambient_color = cn.sphere->details.col;
	if (cn.sphere->details.has_normal_map)
	{
		ray->normal_map = get_sphere_normal_map(&cn, ray->normal);
		ray->bump_mapping = TRUE;
	}
	else
		ray->bump_mapping = FALSE;
}
