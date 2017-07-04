/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/03 14:47:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

t_vector	vector_mult2(int num, t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = num * v1->x * v2->x;
	result.y = num * v1->y * v2->y;
	result.z = num * v1->z * v2->z;
	return (result);
}
