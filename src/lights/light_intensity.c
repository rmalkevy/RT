/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:43:57 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/30 20:24:50 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	define_ray_intensity(double len, double *intensity,
										double decrement, double intens_0)
{
	*intensity = intens_0 * exp(-len * decrement);
}

void	normalise_intensity(double *l_intens, int lights_qnt, double sum)
{
	int			i;
	double		mult;
	double		avg;

	i = 0;
	avg = sum / lights_qnt;
	mult = 1 / avg;
	while (i++ < lights_qnt)
		l_intens[i - 1] *= mult;
}

void	define_sum_intensity(t_light *light, double *sum, double *l_intens)
{
	int			i;
	t_light		*cursor;

	i = 0;
	cursor = light;
	(void)sum;
	(void)l_intens;
	while (cursor)
	{
		l_intens[i] = cursor->get_light_intensity(cursor->source);
		*sum += l_intens[i];
		cursor = cursor->next;
		i++;
	}
}

void	set_light_intensity(t_params *par, t_ray *ray)
{
	double		sum_intensity;

	ray->l_intens = (double *)malloc(sizeof(double) * par->lights_qnt);
	sum_intensity = 0;
	define_sum_intensity(par->lights, &sum_intensity, ray->l_intens);
	if (sum_intensity > 0)
		normalise_intensity(ray->l_intens, par->lights_qnt, sum_intensity);
}
