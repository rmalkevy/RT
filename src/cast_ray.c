/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 12:51:06 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/05 15:14:07 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(t_image *image, t_color *pixel_color, int x, int y)
{
	int			i;

	i = (y * image->sizeline) + (x * 4);
	image->data[i] = pixel_color->blue;
	image->data[i + 1] = pixel_color->green;
	image->data[i + 2] = pixel_color->red;
	image->data[i + 3] = pixel_color->op;
}

void			ray_segment_set_params(t_params *par, t_ray_segment *ray,
												double t, t_ray *ray_details)
{
	(void)ray_details;
	(void)par;
	ray_details->len += t;
	ray->length = t;
	intersection_point(&ray->origin,
						&ray->direction, ray->length,
						&ray->intersection_point);
	ray->coefficients = ray->intersection_object->get_coefficients(
												ray->intersection_object->data);
	ray->bump_mapping = 0;
}

t_object		*find_closest_intersection(t_params *par, t_vector *origin,
										t_vector *direction, double *distance)
{
	double		t;
	t_object	*current;
	t_object	*closest;

	current = par->objects;
	closest = NULL;
	t = 0;
	while (current != NULL)
	{
		if (current->intersects(current->data, origin, direction, &t))
		{
			if ((*distance == -1 || *distance > t) && t > EPSILON)
			{
				*distance = t;
				closest = current;
			}
		}
		current = current->next;
	}
	return (closest);
}

t_color			cast_single_ray(t_params *par, t_ray_segment ray,
															t_ray ray_details)
{
	t_color		color;
	t_color		back;
	double		distance;

	distance = -1.0;
	back = par->env.back;
	ray.intersection_object = find_closest_intersection(par, &(ray.origin),
												&(ray.direction), &distance);
	if (ray.intersection_object)
		ray_segment_set_params(par, &ray, distance, &ray_details);
	if (!ray.intersection_object)
		return (new_color(back.red, back.green, back.blue, 0));
	ray.intersection_object->set_params(&ray);
	if (ray.coefficients.refl && ray_details.refl_depth++ <
												par->env.reflection_depth)
		ray.refl_dir = launch_reflected_ray(par, ray, ray_details,
												&ray.colors.reflection_color);
	if (ray.coefficients.trans && ray_details.refr_depth++
												< par->env.refraction_depth)
		ray.refr_dir = launch_refracted_ray(par, ray, ray_details,
												&ray.colors.refraction_color);
	shade_pixel(par, &ray, &ray_details, NULL);
	color = combine_colors(ray);
	return (color);
}
