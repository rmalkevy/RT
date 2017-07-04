/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:10:49 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/04 19:34:36 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object			*new_sphere(t_sphere *sphere, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = sphere;
	object->id = id;
	object->name = ft_strdup("sphere");
	object->intersects = intersects_sphere;
	object->get_normal = get_sphere_normal;
	object->get_point_color = get_sphere_color;
	object->get_coefficients = get_sphere_coefficients;
	object->set_params = set_sphere_params;
	object->move_object = &move_sphere;
	object->rotate_object = &rotate_sphere;
	return (object);
}

t_object			*new_plain(t_plain *plain, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = plain;
	object->id = id;
	object->name = ft_strdup("plain");
	object->intersects = intersects_plain;
	object->get_normal = get_plain_normal;
	object->get_point_color = get_plain_color;
	object->get_coefficients = get_plain_coefficients;
	object->set_params = set_plain_params;
	object->move_object = &move_plain;
	object->rotate_object = &rotate_plain;
	return (object);
}

t_object			*new_cylinder(t_cylinder *cylinder, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = cylinder;
	object->id = id;
	object->name = ft_strdup("cylinder");
	object->intersects = intersects_cylinder;
	object->get_normal = get_cylinder_normal;
	object->get_point_color = get_cylinder_color;
	object->get_coefficients = get_cylinder_coefficients;
	object->set_params = set_cylinder_params;
	object->move_object = &move_cyl;
	object->rotate_object = &rotate_cyl;
	return (object);
}

t_object			*new_cone(t_cone *cone, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = cone;
	object->id = id;
	object->name = ft_strdup("cone");
	object->intersects = intersects_cone;
	object->get_normal = get_cone_normal;
	object->get_point_color = get_cone_color;
	object->get_coefficients = get_cone_coefficients;
	object->set_params = set_cone_params;
	object->move_object = &move_cone;
	object->rotate_object = &rotate_cone;
	return (object);
}
