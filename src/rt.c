/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:19:44 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 10:52:38 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(int argc, char **argv)
{
	t_params		*par;
	int				i;

	i = 1;
	if (argc != 2)
	{
		ft_putendl("Usage: ./RT <filename>");
		exit(0);
	}
	if (!(par = (t_params *)malloc(sizeof(t_params))))
		error(errno);
	set_initialise_par(par);
	read_file(argv[1], par);
	apply_move_and_rotation(par);
	prepare_and_init_render(par);
	return (0);
}
