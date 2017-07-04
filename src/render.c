/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:32:36 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 14:45:41 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		apply_color(t_params *par, t_color *color, int x, int y)
{
	if (par->env.sepia)
		apply_sepia(color);
	if (par->env.black_and_white)
		apply_black_and_white(color);
	if (par->env.negative)
		apply_negative(color);
	apply_contrast(color, par->env.contrast);
	put_pixel(&par->env.image, color, x, y);
}

void		define_pixel_color(t_params *par, int x, int y)
{
	t_color	color;
	t_ray	*ray;

	color = new_color(0, 0, 0, 0);
	ray = new_ray();
	set_light_intensity(par, ray);
	color = add_color(antialiasing_color(cast_single_ray(par,
					new_ray_segment(par->camera.position.origin, get_direction(
							par->camera.position.origin,
							get_destination_point(par, x, y))),
					*ray), par->env.anti_aliasing), color);
	free_ray(ray);
	apply_color(par, &color, x, y);
}

void		trace_rays(t_params *par)
{
	int			y;
	int			x;

	y = 0;
	while (y < (par->height))
	{
		x = 0;
		while (x < (par->width))
		{
			define_pixel_color(par, x, y);
			x++;
		}
		y++;
	}
}

void		render(t_params *par)
{
	mlx_clear_window(par->env.mlx, par->env.win);
	par->camera.distance = 1000;
	apply_move_and_rotation(par);
	trace_rays(par);
	mlx_put_image_to_window(par->env.mlx, par->env.win,
			par->env.image.ptr, 0, 0);
}
