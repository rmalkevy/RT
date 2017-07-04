/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_base_data_part_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:16:33 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/04 19:25:15 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_disc_data_core(t_disc *disc, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&disc->details, name, space, par);
	if (!ft_strcmp(name, "normal"))
		parse_vector(&disc->normal, space);
	if (!ft_strcmp(name, "radius"))
		disc->radius = fabs(ft_atof(space));
	free(name);
}

void			fill_lim_cyl_data_core(t_limited_cylinder *cyl, char *split,
										char *space, t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&cyl->details, name, space, par);
	if (!ft_strcmp(name, "direction"))
		parse_vector(&cyl->dir, space);
	if (!ft_strcmp(name, "height"))
		cyl->height = fabs(ft_atof(space));
	if (!ft_strcmp(name, "radius"))
		cyl->radius = fabs(ft_atof(space));
	free(name);
}

void			fill_torus_data_core(t_torus *torus, char *split, char *space,
															t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(torus->details), name, space, par);
	if (!ft_strcmp(name, "inradius"))
		torus->inner_radius = fabs(ft_atof(space));
	if (!ft_strcmp(name, "outradius"))
		torus->outer_radius = fabs(ft_atof(space));
	if (!ft_strcmp(name, "direction"))
		parse_vector(&(torus->direction), space);
	free(name);
}

void			fill_ellipse_data_core(t_ellipsoid *ell, char *split,
													char *space, t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(ell->details), name, space, par);
	if (!ft_strcmp(name, "size"))
		parse_vector(&(ell->size), space);
	if (!ft_strcmp(name, "minus"))
		parse_vector(&(ell->q.minus), space);
	if (!ft_strcmp(name, "rot_ellipse"))
		parse_vector(&(ell->rot_ellipse), space);
	free(name);
}

void			fill_hyperboloid_data_core(t_hyperbol *hyp, char *split,
													char *space, t_params *par)
{
	char	*name;
	char	*tmp;

	tmp = ft_strsub(split, 0, space - split);
	name = ft_strtrim(tmp);
	free(tmp);
	fill_common(&(hyp->details), name, space, par);
	if (!ft_strcmp(name, "size"))
		parse_vector(&(hyp->size), space);
	if (!ft_strcmp(name, "minus"))
		parse_vector(&(hyp->q.minus), space);
	if (!ft_strcmp(name, "rot_hyperbol"))
		parse_vector(&(hyp->rot_hyperbol), space);
	free(name);
}
