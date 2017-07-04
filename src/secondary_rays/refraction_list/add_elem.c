/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:21:09 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:27:05 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		refr_lst__add_elem(t_refr_lst **head_lst, int id, double refr_coeff)
{
	t_refr_lst		*elem;

	elem = NULL;
	if (!head_lst)
		return (FALSE);
	if (*head_lst == NULL)
		*head_lst = refr_lst__new_elem(id, refr_coeff);
	else
	{
		elem = *head_lst;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = refr_lst__new_elem(id, refr_coeff);
		return (TRUE);
	}
	return (FALSE);
}
