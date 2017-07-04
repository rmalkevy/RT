/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_refracted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 08:31:55 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/30 19:27:33 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	clear_refracted(t_refr_lst *begin)
{
	t_refr_lst	*cursor;

	cursor = begin;
	while (cursor)
	{
		refr_lst__del_elem(&begin, cursor->id);
		cursor = cursor->next;
	}
}
