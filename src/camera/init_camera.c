/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:33:39 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/31 15:38:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_camera(t_camera *cam)
{
	translate_vector_by_vector(&cam->position.origin, &cam->position.move);
	cam->position.move = new_vector_stack(0, 0, 0);
}

void	rotate_camera_direction(t_camera *cam)
{
	rotate_vector_by_vector(&cam->direction, &cam->position.rotation);
	cam->position.rotation = new_vector_stack(0, 0, 0);
}

void	rotate_camera_dir_x_y(t_camera *cam)
{
	rotate_vector_by_vector(&cam->x_dir, &cam->position.rotation);
	rotate_vector_by_vector(&cam->y_dir, &cam->position.rotation);
}

void	apply_camera_modifications(t_camera *cam)
{
	move_camera(cam);
	rotate_camera_dir_x_y(cam);
	rotate_camera_direction(cam);
}
