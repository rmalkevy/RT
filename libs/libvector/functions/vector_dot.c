/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:28:48 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/07 16:40:13 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

void	vector_dot(t_vector *a, t_vector *b, double *scalar)
{
	*scalar = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}
