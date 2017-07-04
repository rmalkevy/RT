/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_data_part_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:47:35 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 22:14:01 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_torus_data(t_torus *torus, char **split, t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	torus->inner_radius = 100;
	torus->outer_radius = 200;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
			fill_torus_data_core(torus, split[i - 1], space, par);
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	torus->in_radius2 = torus->inner_radius * torus->inner_radius;
	torus->out_radius2 = torus->outer_radius * torus->outer_radius;
	vector_unit(&(torus->direction), &(torus->direction));
	coeff_normalisation(&(torus->details));
}

void			fill_ellipsoid_data(t_ellipsoid *ell, char **split,
															t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
			fill_ellipse_data_core(ell, split[i - 1], space, par);
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	coeff_normalisation(&(ell->details));
}

void			fill_hyperboloid_data(t_hyperbol *hyp, char **split,
																t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
			fill_hyperboloid_data_core(hyp, split[i - 1], space, par);
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	coeff_normalisation(&(hyp->details));
}

void			fill_triangle_data(t_triangle *triangle, char **split)
{
	int		i;
	char	*space;
	char	*name;
	char	*tmp;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
		{
			tmp = ft_strsub(split[i - 1], 0, space - split[i - 1]);
			name = ft_strtrim(tmp);
			free(tmp);
			fill_common_for_obj(&(triangle->details), name, space);
			free(name);
		}
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	coeff_normalisation(&(triangle->details));
}
