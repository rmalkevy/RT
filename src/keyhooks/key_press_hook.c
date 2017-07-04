/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:20:38 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/04 23:35:38 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	key_press_hook_helper(int key, t_params *params)
{
	if (key == KEY_B)
		params->env.black_and_white = params->env.black_and_white ? 0 : 1;
	else if (key == KEY_V)
		params->env.sepia = params->env.sepia ? 0 : 1;
	else if (key == KEY_N)
		params->env.negative = params->env.negative ? 0 : 1;
	else if (key == KEY_G)
		params->env.glares_present = params->env.glares_present ? 0 : 1;
	else if (key == KEY_H)
		params->env.shades_present = params->env.shades_present ? 0 : 1;
}

int		key_press_hook(int key, void *params)
{
	t_params	*par;

	par = (t_params*)params;
	if (key == KEY_ESCAPE)
		exit(0);
	else if (key == KEY_LEFT)
		rotate_camera(par, 0, -10, 0);
	else if (key == KEY_RIGHT)
		rotate_camera(par, 0, 10, 0);
	else if (key == KEY_UP)
		rotate_camera(par, -10, 0, 0);
	else if (key == KEY_DOWN)
		rotate_camera(par, 10, 0, 0);
	else if (key == KEY_W)
		move_camera_hook(par, 0, 0, 50);
	else if (key == KEY_S)
		move_camera_hook(par, 0, 0, -50);
	else if (key == KEY_A)
		move_camera_hook(par, -50, 0, 0);
	else if (key == KEY_D)
		move_camera_hook(par, 50, 0, 0);
	else
		key_press_hook_helper(key, par);
	render(par);
	return (0);
}
