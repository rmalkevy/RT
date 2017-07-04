/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contrast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:54:11 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 23:04:42 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	apply_contrast(t_color *color, int contrast)
{
	double		contrast_factor;
	int			red;
	int			green;
	int			blue;

	contrast_factor = (259. * ((double)contrast + 255.))
					/ (255. * (259. - (double)contrast));
	red = color->red;
	green = color->green;
	blue = color->blue;
	red = contrast_factor * (red - 128) + 128;
	blue = contrast_factor * (blue - 128) + 128;
	green = contrast_factor * (green - 128) + 128;
	red = red > 255 ? 255 : red;
	red = red < 0 ? 0 : red;
	green = green > 255 ? 255 : green;
	green = green < 0 ? 0 : green;
	blue = blue > 255 ? 255 : blue;
	blue = blue < 0 ? 0 : blue;
	color->red = red;
	color->green = green;
	color->blue = blue;
}
