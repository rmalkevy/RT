/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:00:58 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 12:06:43 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_cone_data(t_cone *con, char **split, t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
		{
			fill_cone_data_core(con, split[i - 1], space, par);
		}
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	vector_unit(&(con->direction), &(con->direction));
	coeff_normalisation(&(con->details));
}

void			fill_sphere_data(t_sphere *s, char **split, t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
		{
			fill_sphere_data_core(s, split[i - 1], space, par);
		}
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	vector_unit(&(s->dir_x), &(s->dir_x));
	vector_unit(&(s->dir_y), &(s->dir_y));
	coeff_normalisation(&(s->details));
}

void			fill_cylinder_data(t_cylinder *c, char **split, t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
		{
			fill_cylinder_data_core(c, split[i - 1], space, par);
		}
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	vector_unit(&(c->direction), &(c->direction));
	vector_unit(&(c->dir_x), &(c->dir_x));
	coeff_normalisation(&(c->details));
}

void			fill_plain_data(t_plain *p, char **split, t_params *par)
{
	int		i;
	char	*space;

	i = 0;
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		if ((space = ft_strchr(split[i - 1], ' ')))
		{
			fill_plain_data_core(p, split[i - 1], space, par);
		}
		free(split[i - 1]);
		split[i - 1] = NULL;
	}
	vector_unit(&(p->normal), &(p->normal));
	coeff_normalisation(&(p->details));
}
