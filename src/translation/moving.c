/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:15:39 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/15 19:15:01 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		move_sphere(void *data)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)data;
	translate_vector_by_vector(&sphere->details.pos.origin,
			&sphere->details.pos.move);
	vector_set(0, 0, 0, &sphere->details.pos.move);
}

void		move_plain(void *data)
{
	t_plain		*plain;

	plain = (t_plain*)data;
	translate_vector_by_vector(&plain->details.pos.origin,
			&plain->details.pos.move);
	vector_set(0, 0, 0, &plain->details.pos.move);
}

void		move_cyl(void *data)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder*)data;
	translate_vector_by_vector(&cyl->details.pos.origin,
			&cyl->details.pos.move);
	vector_set(0, 0, 0, &cyl->details.pos.move);
}

void		move_cone(void *data)
{
	t_cone		*cone;

	cone = (t_cone*)data;
	translate_vector_by_vector(&cone->details.pos.origin,
			&cone->details.pos.move);
	vector_set(0, 0, 0, &cone->details.pos.move);
}
