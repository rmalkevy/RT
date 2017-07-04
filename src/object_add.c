/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 07:23:00 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/01 18:22:34 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	object_add(t_object **alst, t_object **new_obj)
{
	if (alst && new_obj && *new_obj)
	{
		(*new_obj)->next = *alst;
		*alst = *new_obj;
	}
}

void	lights_add(t_light **alst, t_light **new)
{
	if (alst && new && *new)
	{
		(*new)->next = *alst;
		*alst = *new;
	}
}
