/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:25:23 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/04 19:12:11 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	apply_negative(t_color *color)
{
	t_color		temp;

	temp = *color;
	temp.green = 255 - color->green;
	temp.red = 255 - color->red;
	temp.blue = 255 - color->blue;
	*color = temp;
}
