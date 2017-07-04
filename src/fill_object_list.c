/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:10:18 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/04 20:33:52 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		fill_object_list(t_params *p, char *dots, t_object *obj, char *name)
{
	if (!ft_strcmp(name, "OBJ"))
		work_with_obj(p, dots);
	else
	{
		if (!ft_strcmp(name, "SPHERE"))
			obj = new_sphere(parse_sphere(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "PLAIN"))
			obj = new_plain(parse_plain(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "CYLINDER"))
			obj = new_cylinder(parse_cylinder(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "CONE"))
			obj = new_cone(parse_cone(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "ELLIPSOID"))
			obj = new_ellipsoid(parse_ellipsoid(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "HYPERBOLOID"))
			obj = new_hyperbol(parse_hyperboloid(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "TORUS"))
			obj = new_torus(parse_torus(dots, p), p->objects_qnt);
		else if (!ft_strcmp(name, "DISC"))
			obj = new_disc(parse_disc(dots, p), p->objects_qnt);
		object_add(&(p->objects), &obj);
		p->objects_qnt++;
	}
}

void		fill_light_list(t_params *p, char *dots, t_light *light, char *name)
{
	if (!ft_strcmp(name, "LIGHT_POINT"))
		light = new_light_point(parse_light_point(dots));
	else if (!ft_strcmp(name, "LIGHT_DIR"))
		light = new_light_dir(parse_light_dir(dots));
	else if (!ft_strcmp(name, "LIGHT_PAR"))
		light = new_parallel_light(parse_parallel_light(dots));
	lights_add(&(p->lights), &light);
	p->lights_qnt++;
}
