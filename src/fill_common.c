/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 08:26:35 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/05 17:42:55 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			coeff_normalisation(t_common *com)
{
	double	sum;

	sum = com->coefficients.amb + com->coefficients.trans
		+ com->coefficients.refl + com->coefficients.refl_light;
	com->coefficients.amb = com->coefficients.amb / sum;
	com->coefficients.trans = com->coefficients.trans / sum;
	com->coefficients.refl = com->coefficients.refl / sum;
	com->coefficients.refl_light = com->coefficients.refl_light / sum;
}

void			fill_common(t_common *com, char *name, char *space,
																t_params *par)
{
	if (!ft_strcmp(name, "origin") || !ft_strcmp(name, "move")
			|| !ft_strcmp(name, "rotation"))
		parse_pos(&(com->pos), name, space);
	else if (!ft_strcmp(name, "color"))
		parse_color(&(com->col), space);
	else if (!ft_strcmp(name, "ambient"))
		com->coefficients.amb = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "transparency"))
		com->coefficients.trans = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "refr_coeff"))
		com->coefficients.refr_coeff = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "refl_light"))
		com->coefficients.refl_light = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "reflection"))
		com->coefficients.refl = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "texture"))
		com->has_texture = read_texture(space, par->env.mlx, &(com->texture));
	else if (!ft_strcmp(name, "normal_map"))
		com->has_normal_map = read_normal_map(space, par->env.mlx,
												&(com->normal_map));
}

void			fill_common_for_obj(t_common *com, char *name, char *space)
{
	if (!ft_strcmp(name, "origin") || !ft_strcmp(name, "move")
		|| !ft_strcmp(name, "rotation"))
		parse_pos(&(com->pos), name, space);
	else if (!ft_strcmp(name, "color"))
		parse_color(&(com->col), space);
	else if (!ft_strcmp(name, "ambient"))
		com->coefficients.amb = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "transparency"))
		com->coefficients.trans = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "refr_coeff"))
		com->coefficients.refr_coeff = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "refl_light"))
		com->coefficients.refl_light = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "reflection"))
		com->coefficients.refl = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "obj"))
	{
		free(com->has_obj);
		com->has_obj = read_obj(space + 1);
	}
	else if (!ft_strcmp(name, "zoom"))
		com->zoom = fabs(ft_atof(space));
	else if (!ft_strcmp(name, "poligons"))
		com->num_poligon = abs(ft_atoi(space));
}
