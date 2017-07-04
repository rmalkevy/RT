/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:22:59 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:30:27 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		button_press_hook(int button, int x, int y, void *params)
{
	t_params	*par;
	t_vector	dir;

	par = (t_params*)params;
	if (button == 1)
	{
		par->kh_info.dist = -1;
		par->kh_info.lmb_pressed = 1;
		par->kh_info.prev_x = x;
		par->kh_info.prev_y = y;
		dir = get_direction(par->camera.position.origin,
				get_destination_point(par, x, y));
		par->kh_info.intersected = find_closest_intersection(par,
				&par->camera.position.origin, &dir, &par->kh_info.dist);
	}
	return (0);
}
