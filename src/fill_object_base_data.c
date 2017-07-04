/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_base_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:15:26 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/01 13:39:58 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_cone_data_core(t_cone *con, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(con->details), name, space, par);
	if (!ft_strcmp(name, "angle"))
		con->angle = fabs(ft_atof(space));
	if (!ft_strcmp(name, "direction"))
		parse_vector(&(con->direction), space);
	free(name);
}

void			fill_sphere_data_core(t_sphere *s, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(s->details), name, space, par);
	if (!ft_strcmp(name, "radius"))
		s->radius = fabs(ft_atof(space));
	if (!ft_strcmp(name, "angle_x"))
		s->angle_x = fabs(ft_atof(space));
	if (!ft_strcmp(name, "angle_y"))
		s->angle_y = fabs(ft_atof(space));
	if (!ft_strcmp(name, "dir_x"))
		parse_vector(&(s->dir_x), space);
	if (!ft_strcmp(name, "dir_y"))
		parse_vector(&(s->dir_y), space);
	free(name);
}

void			fill_cylinder_data_core(t_cylinder *c, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(c->details), name, space, par);
	if (!ft_strcmp(name, "radius"))
		c->radius = fabs(ft_atof(space));
	if (!ft_strcmp(name, "angle_x"))
		c->angle_x = fabs(ft_atof(space));
	if (!ft_strcmp(name, "dir_x"))
		parse_vector(&(c->dir_x), space);
	if (!ft_strcmp(name, "direction"))
		parse_vector(&(c->direction), space);
	free(name);
}

void			fill_plain_data_core(t_plain *p, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(p->details), name, space, par);
	if (!ft_strcmp(name, "normal"))
		parse_vector(&(p->normal), space);
	if (!ft_strcmp(name, "delta_x"))
		p->delta_x = ft_atof(space);
	if (!ft_strcmp(name, "delta_y"))
		p->delta_y = ft_atof(space);
	free(name);
}
