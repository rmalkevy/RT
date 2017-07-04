/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:27:55 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/04 20:34:10 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		parse_object_core(char *name, t_params *par, char *dots)
{
	if (!ft_strcmp(name, "glares_present"))
		par->env.glares_present = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "shades_present"))
		par->env.shades_present = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "back_color"))
		parse_color(&par->env.back, dots + 1);
	else if (!ft_strcmp(name, "sepia"))
		par->env.sepia = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "black_and_white"))
		par->env.black_and_white = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "threads_quantity"))
	{
		if (!(par->threads_quantity = abs(ft_atoi(dots + 1))))
			par->threads_quantity = 1;
	}
	else if (!ft_strcmp(name, "anti_aliasing"))
		par->env.anti_aliasing = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "CAMERA"))
		fill_cam(&(par->camera), dots);
	else
		fill_obj(name, par, dots);
}

void		fill_obj(char *name, t_params *par, char *dots)
{
	t_object		*objects;
	t_light			*lights;

	objects = NULL;
	lights = NULL;
	if (!ft_strcmp(name, "SPHERE") || !ft_strcmp(name, "PLAIN") ||
		!ft_strcmp(name, "CYLINDER") || !ft_strcmp(name, "CONE") ||
		!ft_strcmp(name, "ELLIPSOID") || !ft_strcmp(name, "HYPERBOLOID")
		|| !ft_strcmp(name, "TORUS")
		|| !ft_strcmp(name, "OBJ") || !ft_strcmp(name, "DISC"))
	{
		fill_object_list(par, dots, objects, name);
	}
	else if (!ft_strcmp(name, "LIGHT_POINT") || !ft_strcmp(name, "LIGHT_DIR")
			|| !ft_strcmp(name, "LIGHT_PAR"))
	{
		fill_light_list(par, dots, lights, name);
	}
}

void		set_camera(t_camera *camera)
{
	set_position(&(camera->position));
	camera->position.origin.z = -1000;
	vector_set(0, 0, 1, &camera->direction);
	vector_set(1, 0, 0, &camera->x_dir);
	vector_set(0, 1, 0, &camera->y_dir);
}
