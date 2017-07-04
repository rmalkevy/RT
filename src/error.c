/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:08:36 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/12 12:34:48 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	error(int errnum)
{
	ft_putendl(strerror(errnum));
	exit(0);
}

void	error_add(int errnum)
{
	if (errnum == 1)
		ft_putendl("mistake memory allocation");
	exit(0);
}

void	error_validate(int errnum)
{
	if (errnum == 1)
		ft_putendl("invalid structure of file");
	if (errnum == 2)
		ft_putendl("invalid structure of object");
	if (errnum == 3)
		ft_putendl("invalid window size");
	if (errnum == 4)
		ft_putendl("invalid format of object property");
	exit(0);
}
