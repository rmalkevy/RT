/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_and_white.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:34:44 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/26 16:37:16 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	apply_black_and_white(t_color *color)
{
	unsigned char	luminosity;

	luminosity = (color->red * .21) +
				(color->green * .72) +
				(color->blue * .07);
	color->red = luminosity;
	color->green = luminosity;
	color->blue = luminosity;
}
