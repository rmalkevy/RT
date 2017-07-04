/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:49:07 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 12:19:17 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light			*new_light_point(t_light_point *light_point)
{
	t_light		*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		error(errno);
	light->name = ft_strdup("light_point");
	light->source = light_point;
	light->set_lighting_params = set_light_point_params;
	light->get_light_intensity = get_light_point_intense;
	light->move_light = &move_light_point;
	light->rotate_light = &rotate_light_point;
	return (light);
}

t_light			*new_light_dir(t_direct_light *light_dir)
{
	t_light		*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		error(errno);
	light->name = ft_strdup("light_dir");
	light->source = light_dir;
	light->set_lighting_params = set_light_direct_params;
	light->get_light_intensity = get_light_direct_intense;
	light->move_light = &move_direct_light;
	light->rotate_light = &rotate_direct_light;
	return (light);
}

t_light			*new_parallel_light(t_parallel_light *parallel_light)
{
	t_light		*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		error(errno);
	light->name = ft_strdup("light_par");
	light->source = parallel_light;
	light->set_lighting_params = set_light_parallel_params;
	light->get_light_intensity = get_light_parallel_intense;
	light->move_light = &move_parallel_light;
	light->rotate_light = &rotate_parallel_light;
	return (light);
}
