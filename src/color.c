/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <elyahove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:49:03 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/31 09:38:23 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			new_color(char red, char green, char blue, char op)
{
	t_color		res;

	res.red = (unsigned char)red;
	res.green = (unsigned char)green;
	res.blue = (unsigned char)blue;
	res.op = (unsigned char)op;
	return (res);
}

t_color			antialiasing_color(t_color color, int antialiasing)
{
	color.red /= (double)antialiasing;
	color.green /= (double)antialiasing;
	color.blue /= (double)antialiasing;
	color.op /= (double)antialiasing;
	return (color);
}

t_color			add_color(t_color first, t_color second)
{
	first.red += second.red;
	first.green += second.green;
	first.blue += second.blue;
	first.op += second.blue;
	return (first);
}

t_color			combine_colors(t_ray_segment ray)
{
	t_color		res;

	res.red = ray.colors.ambient_color.red * ray.coefficients.amb
				+ ray.colors.reflection_color.red * ray.coefficients.refl
				+ ray.colors.refraction_color.red * ray.coefficients.trans;
	res.green = ray.colors.ambient_color.green * ray.coefficients.amb
				+ ray.colors.reflection_color.green * ray.coefficients.refl
				+ ray.colors.refraction_color.green * ray.coefficients.trans;
	res.blue = ray.colors.ambient_color.blue * ray.coefficients.amb
				+ ray.colors.reflection_color.blue * ray.coefficients.refl
				+ ray.colors.refraction_color.blue * ray.coefficients.trans;
	res.op = ray.colors.ambient_color.op * ray.coefficients.amb
				+ ray.colors.reflection_color.op * ray.coefficients.refl
				+ ray.colors.refraction_color.op * ray.coefficients.trans;
	return (res);
}
