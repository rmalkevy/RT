/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:42:05 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/31 13:45:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_and_rotate_objects(t_params *p)
{
	t_object	*current;

	current = p->objects;
	while (current)
	{
		current->move_object(current->data);
		current->rotate_object(current->data);
		current = current->next;
	}
}

void	move_and_rotate_lights(t_params *p)
{
	t_light		*current;

	current = p->lights;
	while (current)
	{
		current->move_light(current->source);
		current->rotate_light(current->source);
		current = current->next;
	}
}

void	apply_move_and_rotation(t_params *p)
{
	move_and_rotate_objects(p);
	move_and_rotate_lights(p);
	apply_camera_modifications(&p->camera);
}

void	init_move_and_rotation(t_params *p)
{
	move_and_rotate_objects(p);
	move_and_rotate_lights(p);
	apply_camera_modifications(&p->camera);
}
