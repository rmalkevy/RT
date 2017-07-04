/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:28:48 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/07 16:38:46 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

void	vector_mult(t_vector *a, double k, t_vector *result)
{
	result->x = a->x * k;
	result->y = a->y * k;
	result->z = a->z * k;
}
