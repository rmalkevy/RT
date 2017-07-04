/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_data_part_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:10:25 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:44:26 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			fill_disc_data(t_disc *disc, char **split,
		t_params *par, int f)
{
	int		i;
	char	*space;

	i = -1;
	vector_set(0, 0, -1, &disc->normal);
	disc->radius = 50;
	while (split[++i])
	{
		if (!validate_split(split[i], split, i))
			break ;
		if ((space = ft_strchr(split[i], ' ')))
			fill_disc_data_core(disc, split[i], space, par);
		if (f)
		{
			free(split[i]);
			split[i] = NULL;
		}
	}
	vector_unit(&disc->normal, &disc->normal);
	coeff_normalisation(&(disc->details));
	disc->color = disc->details.col;
}
