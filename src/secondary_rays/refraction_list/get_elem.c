/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:19:57 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:21:41 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_refr_lst		*refr_lst__get_elem(t_refr_lst **head_lst, int id)
{
	t_refr_lst		*elem;

	elem = *head_lst;
	while (elem != NULL)
	{
		if (elem->id == id)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}
