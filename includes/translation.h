/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:21:38 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/01 17:28:13 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TRANSLATION_H
# define __TRANSLATION_H

# include "rt.h"

enum		e_axis
{
	X = 1,
	Y = 2,
	Z = 3
};

void		translate_vector(t_vector *vec, double x, double y, double z);
void		rotate_vector(t_vector *vec, double x, double y, double z);
void		translate_vector_by_vector(t_vector *vec, t_vector *transl);
void		rotate_vector_by_vector(t_vector *vec, t_vector *rotation);

void		rotate_sphere(void *data);
void		rotate_plain(void *data);
void		rotate_cyl(void *data);
void		rotate_cone(void *data);

void		move_sphere(void *data);
void		move_plain(void *data);
void		move_cyl(void *data);
void		move_cone(void *data);

void		rotate_light_point(void *source);
void		rotate_direct_light(void *source);
void		rotate_parallel_light(void *source);

void		move_light_point(void *source);
void		move_direct_light(void *source);
void		move_parallel_light(void *source);

#endif
