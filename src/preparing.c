/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:29:03 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:38:48 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_ray(t_ray *ray)
{
	free(ray->l_intens);
	clear_refracted(ray->refracted);
	free(ray);
}

void	set_initialise_par(t_params *par)
{
	par->env.mlx = mlx_init();
	par->objects = NULL;
	par->lights = NULL;
	par->lights_qnt = 0;
	par->objects_qnt = 1;
	par->threads_quantity = 1;
	par->env.contrast = 0;
	par->env.object_counter = 1;
	par->env.refraction_depth = 0;
	par->env.reflection_depth = 0;
	par->env.glares_present = 1;
	par->env.shades_present = 1;
	par->env.negative = 0;
	par->env.back = new_color(0, 0, 0, 0);
	par->width = 1000;
	par->height = 800;
	par->env.sepia = 0;
	par->env.black_and_white = 0;
	par->env.anti_aliasing = 1;
	par->kh_info.intersected = NULL;
	par->kh_info.prev_x = 0;
	par->kh_info.prev_y = 0;
	par->kh_info.lmb_pressed = 0;
}

void	create_image(t_params *par)
{
	par->env.image.ptr = mlx_new_image(par->env.mlx, par->width,
										par->height);
	par->env.image.data = mlx_get_data_addr(par->env.image.ptr,
							&par->env.image.bpp, &par->env.image.sizeline,
							&par->env.image.endian);
}

void	prepare_and_init_render(t_params *par)
{
	par->env.win = mlx_new_window(par->env.mlx, par->width,
					par->height, "RT");
	create_image(par);
	render(par);
	set_hooks(par);
	mlx_loop(par->env.mlx);
}
