/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_translations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:01:29 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 22:51:57 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_light_point(void *source)
{
	t_light_point	*light;

	light = (t_light_point*)source;
	translate_vector_by_vector(&light->position.origin, &light->position.move);
	light->position.move = new_vector_stack(0, 0, 0);
}

void	move_direct_light(void *source)
{
	t_direct_light	*light;

	light = (t_direct_light*)source;
	translate_vector_by_vector(&light->position.origin, &light->position.move);
	light->position.move = new_vector_stack(0, 0, 0);
}

void	rotate_direct_light(void *source)
{
	t_direct_light	*light;

	light = (t_direct_light*)source;
	rotate_vector_by_vector(&light->direction, &light->position.rotation);
	light->position.rotation = new_vector_stack(0, 0, 0);
}

void	rotate_parallel_light(void *source)
{
	t_parallel_light	*light;

	light = (t_parallel_light*)source;
	rotate_vector_by_vector(&light->direction, &light->rotation);
	light->rotation = new_vector_stack(0, 0, 0);
}
