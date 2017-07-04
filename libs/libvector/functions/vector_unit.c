/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_unit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:28:48 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/03 10:43:59 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

void	vector_unit(t_vector *a, t_vector *b)
{
	double		mod;

	vector_mod(a, &mod);
	b->x = a->x / mod;
	b->y = a->y / mod;
	b->z = a->z / mod;
}
