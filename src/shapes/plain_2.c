/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:16:34 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/01 17:54:35 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_plain_texture(t_pl_map *cn, t_vector ipoint)
{
	t_color		color;

	vector_sub(&ipoint, &cn->plain->details.pos.origin, &cn->dir_i);
	vector_dot(&cn->dir_i, &cn->plain->dir_x, &cn->u);
	vector_dot(&cn->dir_i, &cn->plain->dir_y, &cn->v);
	cn->u = round(cn->u);
	cn->v = round(cn->v);
	cn->u = abs((int)round(((int)cn->u % (cn->plain->details.texture.width))));
	cn->v = abs((int)round(((int)cn->v % (cn->plain->details.texture.height))));
	vector_cos(&cn->dir_i, &cn->plain->dir_x, &cn->cos_u);
	vector_cos(&cn->dir_i, &cn->plain->dir_y, &cn->cos_v);
	cn->u = (cn->cos_u > 0) ?
	((cn->plain->details.texture.width - 1) - cn->u) : cn->u;
	cn->v = (cn->cos_v > 0) ?
	((cn->plain->details.texture.height - 1) - cn->v) : cn->v;
	color = cn->plain->details.texture.color[(int)cn->v][(int)cn->u];
	return (color);
}

t_vector	get_plain_normal_map(t_pl_map *cn, t_vector ipoint, t_vector normal)
{
	t_vector	normal_map;

	normal = (t_vector)normal;
	vector_sub(&ipoint, &cn->plain->details.pos.origin, &cn->dir_i);
	vector_dot(&cn->dir_i, &cn->plain->dir_x, &cn->u);
	vector_dot(&cn->dir_i, &cn->plain->dir_y, &cn->v);
	cn->u = round(cn->u);
	cn->v = round(cn->v);
	cn->u = abs((int)round(((int)cn->u %
									(cn->plain->details.normal_map.width))));
	cn->v = abs((int)round(((int)cn->v %
									(cn->plain->details.normal_map.height))));
	vector_cos(&cn->dir_i, &cn->plain->dir_x, &cn->cos_u);
	vector_cos(&cn->dir_i, &cn->plain->dir_y, &cn->cos_v);
	cn->u = (cn->cos_u > 0) ?
	((cn->plain->details.normal_map.width - 1) - cn->u) : cn->u;
	cn->v = (cn->cos_v > 0) ?
	((cn->plain->details.normal_map.height - 1) - cn->v) : cn->v;
	normal_map = cn->plain->details.normal_map.normal[(int)cn->v][(int)cn->u];
	return (normal_map);
}

void		set_plain_params(void *p)
{
	t_ray_segment	*ray;
	t_pl_map		cn;

	ray = (t_ray_segment *)p;
	cn.plain = (t_plain *)ray->intersection_object->data;
	ray->normal = cn.plain->normal;
	if (cn.plain->details.has_texture)
		ray->colors.ambient_color = get_plain_texture(&cn,
													ray->intersection_point);
	else
		ray->colors.ambient_color = cn.plain->details.col;
	if (cn.plain->details.has_normal_map)
	{
		ray->normal_map = get_plain_normal_map(&cn, ray->intersection_point,
																ray->normal);
		ray->bump_mapping = TRUE;
	}
	else
		ray->bump_mapping = FALSE;
}
