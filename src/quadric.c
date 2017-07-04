/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		quadric_calculations(t_vector origin, t_vector dir, t_quadric *q)
{
	q->v1 = vector_mult2(1, &dir, &dir);
	q->v2.x = 2 * dir.x * dir.y;
	q->v2.y = 2 * dir.y * dir.z;
	q->v2.z = 2 * dir.x * dir.z;
	q->v3 = vector_mult2(2, &origin, &dir);
	q->v4.x = 2 * (dir.x * origin.y + origin.x * dir.y);
	q->v4.y = 2 * (origin.y * dir.z + dir.y * origin.z);
	q->v4.z = 2 * (origin.x * dir.z + dir.x * origin.z);
	vector_mult(&dir, 2, &q->v5);
	q->v6 = vector_mult2(1, &origin, &origin);
	q->v7.x = 2 * origin.x * origin.y;
	q->v7.y = 2 * origin.y * origin.z;
	q->v7.z = 2 * origin.x * origin.z;
	vector_mult(&origin, 2, &q->v8);
}

void		quadric_get_abc(double *a, double *b, double *c, t_quadric *q)
{
	vector_dot(&q->q1, &q->v1, &q->dot1);
	vector_dot(&q->q2, &q->v2, &q->dot2);
	vector_dot(&q->q1, &q->v3, &q->dot3);
	vector_dot(&q->q2, &q->v4, &q->dot4);
	vector_dot(&q->q3, &q->v5, &q->dot5);
	vector_dot(&q->q1, &q->v6, &q->dot6);
	vector_dot(&q->q2, &q->v7, &q->dot7);
	vector_dot(&q->q3, &q->v8, &q->dot8);
	*a = q->dot1 + q->dot2;
	*b = q->dot3 + q->dot4 + q->dot5;
	*c = q->dot6 + q->dot7 + q->dot8 + q->k;
}

void		set_q_figure(t_vector size, t_vector pos, t_quadric *q)
{
	q->a.x = 1 / (size.x * size.x) * q->minus.x;
	q->a.y = 1 / (size.y * size.y) * q->minus.y;
	q->a.z = 1 / (size.z * size.z) * q->minus.z;
	q->q1.x = q->a.x;
	q->q1.y = q->a.y;
	q->q1.z = q->a.z;
	q->q2.x = 0;
	q->q2.y = 0;
	q->q2.z = 0;
	q->q3.x = -q->a.x * pos.x;
	q->q3.y = -q->a.y * pos.y;
	q->q3.z = -q->a.z * pos.z;
	q->k = q->a.x * pos.x * pos.x + q->a.y * pos.y * pos.y +
		q->a.z * pos.z * pos.z - 1;
}
