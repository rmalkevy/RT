/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 22:37:57 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/03 22:41:21 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_disc_color(void *data)
{
	return (((t_disc*)data)->color);
}

t_vector		get_disc_normal(void *data, t_vector i_point)
{
	(void)i_point;
	return (((t_disc*)data)->normal);
}

t_coefficients	get_disc_coefficients(void *data)
{
	return (((t_disc*)data)->details.coefficients);
}

void			move_disc(void *data)
{
	t_disc		*disc;

	disc = (t_disc*)data;
	translate_vector_by_vector(&disc->details.pos.origin,
			&disc->details.pos.move);
	vector_set(0, 0, 0, &disc->details.pos.move);
}

void			rotate_disc(void *data)
{
	t_disc		*disc;

	disc = (t_disc*)data;
	rotate_vector_by_vector(&disc->normal, &disc->details.pos.rotation);
	vector_set(0, 0, 0, &disc->details.pos.rotation);
}
