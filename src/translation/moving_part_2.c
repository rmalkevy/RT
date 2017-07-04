/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_part_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:41:21 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 14:57:50 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		move_hyperbol(void *data)
{
	t_hyperbol		*hyperbol;

	hyperbol = (t_hyperbol*)data;
	translate_vector_by_vector(&hyperbol->details.pos.origin,
										&hyperbol->details.pos.move);
	vector_set(0, 0, 0, &hyperbol->details.pos.move);
}

void		move_ellipse(void *data)
{
	t_ellipsoid		*ellipse;

	ellipse = (t_ellipsoid*)data;
	translate_vector_by_vector(&ellipse->details.pos.origin,
										&ellipse->details.pos.move);
	vector_set(0, 0, 0, &ellipse->details.pos.move);
}

void		move_triangle(void *data)
{
	t_triangle		*triangle;

	triangle = (t_triangle*)data;
	translate_vector_by_vector(&triangle->a,
							&triangle->details.pos.move);
	translate_vector_by_vector(&triangle->b,
							&triangle->details.pos.move);
	translate_vector_by_vector(&triangle->c,
							&triangle->details.pos.move);
	vector_set(0, 0, 0, &triangle->details.pos.move);
}

void		move_torus(void *data)
{
	t_torus		*torus;

	torus = (t_torus*)data;
	translate_vector_by_vector(&torus->details.pos.origin,
									&torus->details.pos.move);
	vector_set(0, 0, 0, &torus->details.pos.move);
}
