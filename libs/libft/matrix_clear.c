/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 11:28:04 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/25 11:28:05 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_mult.h"

void		matrix_clear(t_matr *m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m->h)
	{
		j = 0;
		while (j < m->w)
		{
			if (i == j)
				m->mt[i][j] = 1;
			else
				m->mt[i][j] = 0;
			j++;
		}
		i++;
	}
}
