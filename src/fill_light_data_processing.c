/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light_data_processing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:42:29 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/04 18:11:26 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		par_light_processing(t_parallel_light *light, char *name,
																char *space)
{
	if (!ft_strcmp(name, "direction"))
	{
		parse_vector(&(light->direction), space);
		vector_unit(&(light->direction), &(light->direction));
	}
	else if (!ft_strcmp(name, "color"))
		parse_color(&(light->params.color), space);
	else if (!ft_strcmp(name, "intensity"))
		light->params.intensity = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "decrement"))
		light->params.decrement = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "rotation"))
		parse_vector(&light->rotation, space);
}

void		point_light_processing(t_light_point *light, char *name,
															char *space)
{
	if (!ft_strcmp(name, "origin") || !ft_strcmp(name, "move")
		|| !ft_strcmp(name, "rotation"))
		parse_pos(&(light->position), name, space);
	else if (!ft_strcmp(name, "color"))
	{
		parse_color(&(light->params.color), space);
	}
	else if (!ft_strcmp(name, "intensity"))
		light->params.intensity = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "decrement"))
		light->params.decrement = fabs(ft_atof(space));
}

void		dir_light_processing(t_direct_light *light, char *name,
																char *space)
{
	if (!ft_strcmp(name, "origin") || !ft_strcmp(name, "move")
		|| !ft_strcmp(name, "rotation"))
		parse_pos(&(light->position), name, space);
	else if (!ft_strcmp(name, "color"))
		parse_color(&(light->params.color), space);
	else if (!ft_strcmp(name, "intensity"))
		light->params.intensity = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "decrement"))
		light->params.decrement = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "direction"))
	{
		parse_vector(&(light->direction), space);
		vector_unit(&(light->direction), &(light->direction));
	}
	else if (!ft_strcmp(name, "angle"))
		light->angle = (M_PI / 180) * fabs(ft_atof(space));
}
