/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic_part4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double	add_root3(double x)
{
	double s;
	double r;

	s = 1.;
	while (x < 1.)
	{
		x *= 8.;
		s *= 0.5;
	}
	while (x > 8.)
	{
		x *= 0.125;
		s *= 2.;
	}
	r = 1.5;
	r -= 1. / 3. * (r - x / (r * r));
	r -= 1. / 3. * (r - x / (r * r));
	r -= 1. / 3. * (r - x / (r * r));
	r -= 1. / 3. * (r - x / (r * r));
	r -= 1. / 3. * (r - x / (r * r));
	r -= 1. / 3. * (r - x / (r * r));
	return (r * s);
}

double	root3(double x)
{
	if (x > 0)
		return (add_root3(x));
	else if (x < 0)
		return (-add_root3(-x));
	else
		return (0.);
}

int		part1_solve_p3(double *x, double r, double *q, double a)
{
	double t;

	t = r / sqrt(q[1]);
	if (t < -1)
		t = -1;
	if (t > 1)
		t = 1;
	t = acos(t);
	a /= 3;
	q[0] = -2 * sqrt(q[0]);
	x[0] = q[0] * cos(t / 3) - a;
	x[1] = q[0] * cos((t + TWOPI) / 3) - a;
	x[2] = q[0] * cos((t - TWOPI) / 3) - a;
	return (3);
}

int		part2_solve_p3(double *x, double r, double *q, double a)
{
	double aa;
	double bb;

	aa = -root3(fabs(r) + sqrt((r * r) - q[1]));
	if (r < 0)
		aa = -aa;
	bb = (aa == 0) ? 0 : q[0] / aa;
	a /= 3;
	x[0] = (aa + bb) - a;
	x[1] = -0.5 * (aa + bb) - a;
	x[2] = 0.5 * sqrt(3.) * (aa - bb);
	if (fabs(x[2]) < EPSILON)
	{
		x[2] = x[1];
		return (2);
	}
	return (1);
}

int		solve_p3(double *x, double a, double b, double c)
{
	double a2;
	double q[2];
	double r[2];

	a2 = a * a;
	q[0] = (a2 - 3 * b) / 9;
	r[0] = (a * (2 * a2 - 9 * b) + 27 * c) / 54;
	r[1] = r[0] * r[0];
	q[1] = q[0] * q[0] * q[0];
	if (r[1] < q[1])
		return (part1_solve_p3(x, r[0], q, a));
	else
		return (part2_solve_p3(x, r[0], q, a));
}
