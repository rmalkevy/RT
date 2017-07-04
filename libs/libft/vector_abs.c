/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:31:38 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/24 13:31:39 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		vector_abs(t_vector *a)
{
	double		abs;

	abs = fabs(sqrt(dot_product(a, a)));
	return (abs);
}