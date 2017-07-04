/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/06/03 11:13:20 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double			find_abcd(t_torus *torus, t_vector *origin, t_vector *dir)
{
	t_vector	centr_orig;
	double		dot_centr_orig_dir;
	double		centr_orig2;
	double		dot_centr_orig_tor_dir;
	double		dot_dir_tor_dir;

	vector_sub(origin, &torus->details.pos.origin, &centr_orig);
	vector_dot(&centr_orig, dir, &dot_centr_orig_dir);
	vector_dot(&centr_orig, &centr_orig, &centr_orig2);
	vector_dot(&centr_orig, &torus->direction, &dot_centr_orig_tor_dir);
	vector_dot(dir, &torus->direction, &dot_dir_tor_dir);
	torus->q.a = 1 - dot_dir_tor_dir * dot_dir_tor_dir;
	vector_dot(dir, &centr_orig, &torus->q.b);
	torus->q.b = 2 * (torus->q.b - dot_centr_orig_tor_dir * dot_dir_tor_dir);
	torus->q.c = centr_orig2 - dot_centr_orig_tor_dir * dot_centr_orig_tor_dir;
	torus->q.d = centr_orig2 + torus->out_radius2 - torus->in_radius2;
	return (dot_centr_orig_dir);
}

void			find_edcb(t_torus *torus, double dot, double *bcde)
{
	double bb;
	double cc;
	double dd;
	double ee;

	bb = 4 * dot;
	cc = 2 * torus->q.d + bb * bb * 0.25 - 4 * torus->out_radius2 * torus->q.a;
	dd = bb * torus->q.d - 4 * torus->out_radius2 * torus->q.b;
	ee = torus->q.d * torus->q.d - 4 * torus->out_radius2 * torus->q.c;
	bcde[0] = bb;
	bcde[1] = cc;
	bcde[2] = dd;
	bcde[3] = ee;
}

double			find_t_torus(t_torus *tor, t_vector *dir,
							t_vector *orig, double *t)
{
	int		count_roots;
	double	closest_root;
	double	bcde[4];
	double	var;
	int		i;

	closest_root = 20000;
	var = find_abcd(tor, orig, dir);
	find_edcb(tor, var, bcde);
	count_roots = solve_quartic_4(t, bcde);
	i = -1;
	while (++i < count_roots)
	{
		var = t[i];
		if (var > 0.000000000001 && var < closest_root)
			closest_root = var;
	}
	if (closest_root == 20000)
		closest_root = -1;
	return (closest_root);
}

void			set_torus_params(void *p)
{
	t_ray_segment	*ray;

	ray = (t_ray_segment *)p;
	ray->normal = ray->intersection_object->get_normal(
					ray->intersection_object->data, ray->intersection_point);
	ray->colors.ambient_color = ray->intersection_object->get_point_color(
												ray->intersection_object->data);
}
