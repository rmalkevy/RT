/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_release_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:23:31 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:44:52 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_sphere_move(void *data, t_vector *move)
{
	t_sphere	*sp;

	sp = (t_sphere*)data;
	vector_sum(&sp->details.pos.move, move, &sp->details.pos.move);
}

int		button_release_hook(int button, int x, int y, void *params)
{
	t_params	*par;
	int			dif_x;
	int			dif_y;
	t_vector	temp;
	double		factor;

	par = (t_params*)params;
	if (button == 1 && par->kh_info.intersected)
	{
		factor = par->kh_info.dist / par->camera.distance;
		dif_x = (x - par->kh_info.prev_x) * factor;
		dif_y = (y - par->kh_info.prev_y) * factor;
		vector_mult(&par->camera.x_dir, dif_x, &temp);
		set_sphere_move(par->kh_info.intersected->data, &temp);
		vector_mult(&par->camera.y_dir, dif_y, &temp);
		set_sphere_move(par->kh_info.intersected->data, &temp);
	}
	render(par);
	return (0);
}
