/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:28:48 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/07 16:40:53 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_lib.h"

void	vector_cos(t_vector *a, t_vector *b, double *value)
{
	double mod_a;
	double mod_b;
	double c;

	vector_mod(a, &mod_a);
	vector_mod(b, &mod_b);
	vector_dot(a, b, &c);
	*value = c / (mod_a * mod_b);
}
