/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 13:07:14 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 09:34:37 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	define_cos_phi(double *cos_phi, t_vector *normal, t_vector *dir,
																	int shading)
{
	vector_dot(normal, dir, cos_phi);
	if (*cos_phi < 0 || shading == 0)
		*cos_phi = 0;
}

void	define_cos_teta(double *cos_teta, t_vector *ray_dir,
											t_vector *shadow_dir, int shading)
{
	vector_dot(shadow_dir, ray_dir, cos_teta);
	if (*cos_teta < 0 || shading == 0)
		*cos_teta = 0;
}

void	shade_and_glare_ambient(t_color *color, t_shadow_ray *shadow_ray,
												double cosinus, t_params *par)
{
	t_color		l_col;
	double		mult;
	double		cos_pow;
	double		count;
	double		glare;

	l_col = shadow_ray->options.color;
	count = (double)par->lights_qnt;
	glare = (double)par->env.glares_present;
	mult = shadow_ray->options.intensity * glare / count;
	cos_pow = pow(cosinus, 10);
	color->red += (l_col.red - color->red) * (0.5 * cos_pow
												+ 0.5 * cosinus) * mult;
	color->green += (l_col.green - color->green) * (0.5 * cos_pow
													+ 0.5 * cosinus) * mult;
	color->blue += (l_col.blue - color->blue) * (0.5 * cos_pow
													+ 0.5 * cosinus) * mult;
	color->op += 250 * 0.8 * (1 - shadow_ray->options.intensity
													* pow(cosinus, 2)) / count;
}

void	shade_and_glare_reflection(t_color *color, t_shadow_ray *shadow_ray,
												double cosinus, t_params *par)
{
	t_color		l_col;
	double		mult;
	double		cos_pow;
	double		count;
	double		glare;

	l_col = shadow_ray->options.color;
	count = (double)par->lights_qnt;
	glare = (double)par->env.glares_present;
	mult = shadow_ray->options.intensity * glare / count;
	cos_pow = pow(cosinus, 2);
	color->red += (l_col.red - color->red) * cos_pow * mult;
	color->green += (l_col.green - color->green) * cos_pow * mult;
	color->blue += (l_col.blue - color->blue) * cos_pow * mult;
}

void	define_shade_and_glare(t_params *par, t_shadow_ray *shadow_ray,
													t_ray_segment *ray_segment)
{
	shade_and_glare_ambient(&(ray_segment->colors.ambient_color),
										shadow_ray, shadow_ray->cos_phi, par);
	shade_and_glare_reflection(&(ray_segment->colors.reflection_color),
										shadow_ray, shadow_ray->cos_teta, par);
}
