/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:37:33 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 12:21:23 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cone			*parse_cone(char *str, t_params *par)
{
	t_cone		*con;
	char		**split;

	if (!(con = (t_cone *)malloc(sizeof(t_cone))))
		error(errno);
	set_initialise(&(con->details));
	con->angle = 30;
	vector_set(0, 1, 0, &con->direction);
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_cone_data(con, split, par);
		free(split);
		split = NULL;
	}
	return (con);
}

t_cylinder		*parse_cylinder(char *str, t_params *par)
{
	t_cylinder	*c;
	char		**split;

	if (!(c = (t_cylinder *)malloc(sizeof(t_cylinder))))
		error(errno);
	set_initialise(&(c->details));
	c->radius = 1;
	c->angle_x = 0;
	vector_set(0, 1, 0, &(c->direction));
	vector_set(1, 0, 0, &(c->dir_x));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_cylinder_data(c, split, par);
		free(split);
		split = NULL;
	}
	return (c);
}

t_sphere		*parse_sphere(char *str, t_params *par)
{
	t_sphere	*s;
	char		**split;

	if (!(s = (t_sphere *)malloc(sizeof(t_sphere))))
		error(errno);
	set_initialise(&(s->details));
	s->radius = 1;
	s->angle_x = 0;
	s->angle_y = 0;
	vector_set(1, 0, 0, &s->dir_x);
	vector_set(1, 0, 0, &s->dir_y);
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_sphere_data(s, split, par);
		free(split);
		split = NULL;
	}
	return (s);
}

t_plain			*parse_plain(char *str, t_params *par)
{
	t_plain		*p;
	char		**split;

	if (!(p = (t_plain *)malloc(sizeof(t_plain))))
		error(errno);
	set_initialise(&(p->details));
	vector_set(0, 1, 0, &p->normal);
	p->delta_x = 1;
	p->delta_y = 1;
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_plain_data(p, split, par);
		free(split);
		split = NULL;
	}
	return (p);
}
