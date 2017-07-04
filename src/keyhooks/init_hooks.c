/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:13:29 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/15 18:19:42 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_hooks(t_params *par)
{
	mlx_hook(par->env.win, 17, 0, window_destroyed_hook, par);
	mlx_hook(par->env.win, 2, 0, key_press_hook, par);
	mlx_hook(par->env.win, 3, 0, key_release_hook, par);
	mlx_hook(par->env.win, 4, 0, button_press_hook, par);
	mlx_hook(par->env.win, 5, 0, button_release_hook, par);
}
