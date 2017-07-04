/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:37:55 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/01 13:39:33 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

void		rotate_sphere(void *data)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)data;
	rotate_vector_by_vector(&sphere->dir_x, &sphere->details.pos.rotation);
	rotate_vector_by_vector(&sphere->dir_y, &sphere->details.pos.rotation);
	vector_set(0, 0, 0, &sphere->details.pos.rotation);
}

void		rotate_plain(void *data)
{
	t_plain		*plain;

	plain = (t_plain*)data;
	rotate_vector_by_vector(&plain->normal, &plain->details.pos.rotation);
	vector_set(0, 0, 0, &plain->details.pos.rotation);
	set_affine_vectors(plain);
}

void		rotate_cyl(void *data)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder*)data;
	rotate_vector_by_vector(&cyl->direction, &cyl->details.pos.rotation);
	rotate_vector_by_vector(&cyl->dir_x, &cyl->details.pos.rotation);
	vector_set(0, 0, 0, &cyl->details.pos.rotation);
}

void		rotate_cone(void *data)
{
	t_cone		*cone;

	cone = (t_cone*)data;
	rotate_vector_by_vector(&cone->direction, &cone->details.pos.rotation);
	vector_set(0, 0, 0, &cone->details.pos.rotation);
}
