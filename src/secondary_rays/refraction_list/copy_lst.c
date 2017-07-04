/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:45:03 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:21:00 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_refr_lst		*refr_lst__copy_lst(t_refr_lst **old_lst)
{
	t_refr_lst		*new_lst;
	t_refr_lst		*elem;

	if (!old_lst)
		return (NULL);
	new_lst = NULL;
	elem = *old_lst;
	while (elem)
	{
		refr_lst__add_elem(&new_lst, elem->id, elem->refr_coeff);
		elem = elem->next;
	}
	return (new_lst);
}
