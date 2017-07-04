/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:24:55 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/31 14:25:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	apply_sepia(t_color *color)
{
	int		rgb[3];

	rgb[0] = (color->red * .393) + (color->green * .769) + (color->blue * .189);
	rgb[0] = rgb[0] > 255 ? 255 : rgb[0];
	rgb[1] = (color->red * .349) + (color->green * .686) + (color->blue * .168);
	rgb[1] = rgb[1] > 255 ? 255 : rgb[1];
	rgb[2] = (color->red * .272) + (color->green * .354) + (color->blue * .131);
	rgb[2] = rgb[2] > 255 ? 255 : rgb[2];
	color->red = rgb[0];
	color->green = rgb[1];
	color->blue = rgb[2];
}
