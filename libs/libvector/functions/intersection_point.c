/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:08:34 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/03 10:43:42 by kandreyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

void	intersection_point(t_vector *a, t_vector *b, double k, t_vector *v)
{
	v->x = b->x * k;
	v->y = b->y * k;
	v->z = b->z * k;
	vector_sum(a, v, v);
}
