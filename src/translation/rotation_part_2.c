/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_part_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:43:31 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 14:58:08 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		rotate_hyperbol(void *data)
{
	t_hyperbol		*hyperbol;

	hyperbol = (t_hyperbol*)data;
	rotate_vector_by_vector(&hyperbol->size, &hyperbol->details.pos.rotation);
	vector_set(0, 0, 0, &hyperbol->details.pos.rotation);
	set_q_figure(hyperbol->size, hyperbol->details.pos.origin, &hyperbol->q);
}

void		rotate_ellipse(void *data)
{
	t_ellipsoid		*ellipse;

	ellipse = (t_ellipsoid*)data;
	rotate_vector_by_vector(&ellipse->size, &ellipse->details.pos.rotation);
	vector_set(0, 0, 0, &ellipse->details.pos.rotation);
	set_q_figure(ellipse->size, ellipse->details.pos.origin, &ellipse->q);
}

void		rotate_triangle(void *data)
{
	t_triangle		*triangle;

	triangle = (t_triangle*)data;
	rotate_vector_by_vector(&triangle->a, &triangle->details.pos.rotation);
	rotate_vector_by_vector(&triangle->b, &triangle->details.pos.rotation);
	rotate_vector_by_vector(&triangle->c, &triangle->details.pos.rotation);
	vector_set(0, 0, 0, &triangle->details.pos.rotation);
	vector_sub(&triangle->b, &triangle->a, &triangle->edge1);
	vector_sub(&triangle->c, &triangle->a, &triangle->edge2);
	vector_cross(&triangle->edge1, &triangle->edge2, &triangle->normal);
	vector_unit(&triangle->normal, &triangle->normal);
}

void		rotate_torus(void *data)
{
	t_torus		*torus;

	torus = (t_torus*)data;
	rotate_vector_by_vector(&torus->direction, &torus->details.pos.rotation);
	vector_set(0, 0, 0, &torus->details.pos.rotation);
}
