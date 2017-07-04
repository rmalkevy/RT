/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:21:09 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:26:48 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			refr_lst__del_elem(t_refr_lst **head_lst, int id)
{
	t_refr_lst		*elem;
	t_refr_lst		*prev;

	prev = NULL;
	if (!head_lst)
		return (FALSE);
	elem = *head_lst;
	while (elem)
	{
		if (elem->id == id)
		{
			prev = refr_lst__get_prev_elem(head_lst, id);
			if (prev == NULL)
				*head_lst = elem->next;
			else
				prev->next = elem->next;
			free(elem);
			elem = NULL;
			return (TRUE);
		}
		elem = elem->next;
	}
	return (FALSE);
}
