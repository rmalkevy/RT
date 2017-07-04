/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_contrast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 19:02:09 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:42:12 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_contrast(t_params *par, char *dots)
{
	double	contrast;

	contrast = ft_atof(dots);
	contrast = contrast > 1. ? 1. : contrast;
	contrast = contrast < 0 ? 0 : contrast;
	contrast = (contrast * 255.) - 128.;
	par->env.contrast = contrast;
}
