/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:23:41 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 20:00:34 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			set_light_direct_params(void *source,
								t_shadow_ray *ray, t_ray *ray_details, int i)
{
	t_direct_light	*light;
	t_vector		tmp;
	double			new_angle;

	light = (t_direct_light*)source;
	vector_sub(&light->position.origin, &ray->origin, &tmp);
	vector_mod(&tmp, &ray->length);
	vector_unit(&tmp, &ray->direction);
	vector_dot(&ray->direction, &light->direction, &new_angle);
	ray->options = light->params;
	define_ray_intensity(ray->length + ray_details->len,
	&(ray->options.intensity),
	ray->options.decrement, ray_details->l_intens[i]);
	ray->shading = (-new_angle > cos(light->angle)) ? 1 : 0;
	return ((-new_angle > cos(light->angle)) ? TRUE : FALSE);
}

double		get_light_direct_intense(void *source)
{
	t_direct_light	*light;

	light = (t_direct_light	*)source;
	return (light->params.intensity);
}
