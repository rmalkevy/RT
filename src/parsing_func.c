/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:07:09 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/05 17:37:39 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_position(t_pos *pos)
{
	pos->origin.x = 0;
	pos->origin.y = 0;
	pos->origin.z = 0;
	pos->move.x = 0;
	pos->move.y = 0;
	pos->move.z = 0;
	pos->rotation.x = 0;
	pos->rotation.y = 0;
	pos->rotation.z = 0;
}

void		set_initialise(t_common *com)
{
	com->col.red = 0;
	com->col.green = 0;
	com->col.blue = 0;
	com->col.op = 0;
	set_position(&(com->pos));
	com->coefficients.amb = 1;
	com->coefficients.refl = 0;
	com->coefficients.trans = 0;
	com->coefficients.refl_light = 0;
	com->coefficients.refr_coeff = 1;
	com->has_texture = FALSE;
	com->has_normal_map = FALSE;
	com->has_obj = ft_strdup("not-existing-file-1234567890");
	com->num_poligon = 30000;
	com->zoom = 1;
}

void		parse_vector(t_vector *origin, char *str)
{
	char	*begin;

	begin = ft_strchr(str, '(');
	if (!begin)
		error_validate(4);
	origin->x = ft_atof(begin + 1);
	begin = ft_strchr(begin + 1, ',');
	if (!begin)
		error_validate(4);
	origin->y = ft_atof(begin + 1);
	begin = ft_strchr(begin + 1, ',');
	if (!begin)
		error_validate(4);
	origin->z = ft_atof(begin + 1);
	begin = ft_strchr(begin + 1, ')');
	if (!begin)
		error_validate(4);
}

void		parse_color(t_color *col, char *str)
{
	char	*begin;

	begin = ft_strchr(str, '(');
	if (!begin)
		error_validate(4);
	col->red = ft_atoi(begin + 1);
	begin = ft_strchr(begin + 1, ',');
	if (!begin || col->red > 255 || col->red < 0)
		error_validate(4);
	col->green = ft_atoi(begin + 1);
	begin = ft_strchr(begin + 1, ',');
	if (!begin || col->green > 255 || col->green < 0)
		error_validate(4);
	col->blue = ft_atoi(begin + 1);
	begin = ft_strchr(begin + 1, ')');
	if (!begin || col->blue > 255 || col->blue < 0)
		error_validate(4);
}

void		parse_pos(t_pos *pos, char *name, char *space)
{
	if (!ft_strcmp(name, "origin"))
		parse_vector(&(pos->origin), space);
	else if (!ft_strcmp(name, "move"))
		parse_vector(&(pos->move), space);
	else if (!ft_strcmp(name, "rotation"))
		parse_vector(&(pos->rotation), space);
}
