/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:23:41 by kandreyc          #+#    #+#             */
/*   Updated: 2017/05/30 20:19:24 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			set_light_parallel_params(void *source, t_shadow_ray *ray,
													t_ray *ray_details, int i)
{
	t_parallel_light	*light;

	light = (t_parallel_light*)source;
	ray->length = END;
	vector_mult(&light->direction, -1, &ray->direction);
	vector_unit(&ray->direction, &ray->direction);
	ray->options = light->params;
	define_ray_intensity(ray_details->len, &(ray->options.intensity),
	ray->options.decrement, ray_details->l_intens[i]);
	ray->shading = 1;
	return (TRUE);
}

double		get_light_parallel_intense(void *source)
{
	t_parallel_light	*light;

	light = (t_parallel_light *)source;
	return (light->params.intensity);
}
