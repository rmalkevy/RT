/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prev_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:21:09 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:21:47 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_refr_lst		*refr_lst__get_prev_elem(t_refr_lst **head_lst, int id)
{
	t_refr_lst		*elem;

	elem = *head_lst;
	if (elem == NULL)
		return (NULL);
	while (elem->next != NULL)
	{
		if (elem->next->id == id)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
