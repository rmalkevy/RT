/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_part_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:46:05 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/05 14:45:21 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_disc				*parse_disc(char *str, t_params *par)
{
	t_disc		*disc;
	char		**split;

	if (!(disc = (t_disc*)malloc(sizeof(t_disc))))
		error(errno);
	set_initialise(&(disc->details));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_disc_data(disc, split, par, 1);
		free(split);
		split = NULL;
	}
	return (disc);
}

t_torus				*parse_torus(char *str, t_params *par)
{
	t_torus		*torus;
	char		**split;

	if (!(torus = (t_torus *)malloc(sizeof(t_torus))))
		error(errno);
	set_initialise(&(torus->details));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_torus_data(torus, split, par);
		free(split);
		split = NULL;
	}
	return (torus);
}

t_ellipsoid			*parse_ellipsoid(char *str, t_params *par)
{
	t_ellipsoid	*ell;
	char		**split;

	if (!(ell = (t_ellipsoid *)malloc(sizeof(t_ellipsoid))))
		error(errno);
	set_initialise(&(ell->details));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_ellipsoid_data(ell, split, par);
		free(split);
		split = NULL;
	}
	return (ell);
}

t_hyperbol			*parse_hyperboloid(char *str, t_params *par)
{
	t_hyperbol	*hyperbol;
	char		**split;

	if (!(hyperbol = (t_hyperbol *)malloc(sizeof(t_hyperbol))))
		error(errno);
	set_initialise(&(hyperbol->details));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_hyperboloid_data(hyperbol, split, par);
		free(split);
		split = NULL;
	}
	return (hyperbol);
}

t_triangle			*parse_triangle(char *str)
{
	t_triangle	*triangle;
	char		**split;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		error(errno);
	set_initialise(&(triangle->details));
	if (str)
	{
		if (!(split = ft_strsplit(str, '\n')))
			error_add(1);
		fill_triangle_data(triangle, split);
		free(split);
		split = NULL;
	}
	return (triangle);
}
