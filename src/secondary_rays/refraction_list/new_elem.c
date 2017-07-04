/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:18:39 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 19:25:25 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_refr_lst		*refr_lst__new_elem(int id, double refr_coeff)
{
	t_refr_lst		*new_elem;

	new_elem = (t_refr_lst *)malloc(sizeof(t_refr_lst));
	if (!new_elem)
		return (NULL);
	new_elem->id = id;
	new_elem->refr_coeff = refr_coeff;
	new_elem->include = 1;
	new_elem->eff_refr = refr_coeff;
	new_elem->next = NULL;
	return (new_elem);
}
