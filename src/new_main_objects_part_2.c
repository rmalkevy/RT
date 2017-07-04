/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main_objects_part_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:37:21 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 22:36:42 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object			*new_ellipsoid(t_ellipsoid *ellipse, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = ellipse;
	object->id = id;
	object->name = ft_strdup("ellipsoid");
	object->intersects = intersects_ellipse;
	object->get_normal = get_ellipse_normal;
	object->get_point_color = get_ellipse_color;
	object->set_params = set_ellipse_params;
	object->get_coefficients = get_ellipse_coefficients;
	object->move_object = &move_ellipse;
	object->rotate_object = &rotate_ellipse;
	return (object);
}

t_object			*new_hyperbol(t_hyperbol *hyperbol, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = hyperbol;
	object->id = id;
	object->name = ft_strdup("hyperbol");
	object->intersects = intersects_hyperbol;
	object->get_normal = get_hyperbol_normal;
	object->get_point_color = get_hyperbol_color;
	object->set_params = set_hyper_params;
	object->get_coefficients = get_hyperbol_coefficients;
	object->move_object = &move_hyperbol;
	object->rotate_object = &rotate_hyperbol;
	return (object);
}

t_object			*new_torus(t_torus *torus, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = torus;
	object->id = id;
	object->name = ft_strdup("torus");
	object->intersects = intersects_torus;
	object->get_normal = get_torus_normal;
	object->get_point_color = get_torus_color;
	object->set_params = set_torus_params;
	object->get_coefficients = get_torus_coefficients;
	object->move_object = &move_torus;
	object->rotate_object = &rotate_torus;
	return (object);
}

t_object			*new_triangle(t_triangle *triangle, int id)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(errno);
	object->data = triangle;
	object->id = id;
	object->name = ft_strdup("triangle");
	object->intersects = intersects_triangle;
	object->get_normal = get_triangle_normal;
	object->get_point_color = get_triangle_color;
	object->set_params = set_triangle_params;
	object->get_coefficients = get_triangle_coefficients;
	object->move_object = &move_triangle;
	object->rotate_object = &rotate_triangle;
	return (object);
}
