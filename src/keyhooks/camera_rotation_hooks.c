/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation_hooks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 23:08:17 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:44:36 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_camera(t_params *par, double x, double y, double z)
{
	vector_set(par->camera.position.rotation.x + x,
			par->camera.position.rotation.y + y,
			par->camera.position.rotation.z + z,
			&par->camera.position.rotation);
}

void	move_camera_hook(t_params *par, double x, double y, double z)
{
	vector_set(par->camera.position.move.x + x,
			par->camera.position.move.y + y,
			par->camera.position.move.z + z,
			&par->camera.position.move);
}
