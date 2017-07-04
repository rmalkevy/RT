/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:23:41 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 20:21:31 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			set_light_point_params(void *source, t_shadow_ray *ray,
												t_ray *ray_details, int i)
{
	t_light_point	*light;
	t_vector		tmp;

	light = (t_light_point*)source;
	vector_sub(&light->position.origin, &ray->origin, &tmp);
	vector_mod(&tmp, &ray->length);
	vector_unit(&tmp, &ray->direction);
	ray->options = light->params;
	define_ray_intensity(ray->length + ray_details->len,
	&(ray->options.intensity),
	ray->options.decrement, ray_details->l_intens[i]);
	ray->shading = 1;
	return (TRUE);
}

double		get_light_point_intense(void *source)
{
	t_light_point	*light;

	light = (t_light_point *)source;
	return (light->params.intensity);
}
