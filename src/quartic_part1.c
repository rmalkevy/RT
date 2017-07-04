/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double	n4step(double x, double *q)
{
	double fxs;
	double fx;

	fxs = ((4 * x + 3 * q[0]) * x + 2 * q[1]) * x + q[2];
	if (fxs == 0)
		return (1e99);
	fx = (((x + q[0]) * x + q[1]) * x + q[2]) * x + q[3];
	return (x - fx / fxs);
}

void	add_solve_quartic_4(double *x, double a, int res)
{
	x[0] -= a / 4;
	x[2] -= a / 4;
	if (res == 4)
	{
		x[1] -= a / 4;
		x[3] -= a / 4;
	}
	else if (res == 2)
		x[1] -= a / 4;
}

int		solve_quartic_4(double *x, double *q)
{
	double	d1;
	double	c1;
	double	b1;
	int		res;
	double	q3;

	q3 = q[0] * q[0] * q[0];
	d1 = q[3] + 0.25 * q[0] * (0.25 * q[1] * q[0] - 3. / 64 * q3 - q[2]);
	c1 = q[2] + 0.5 * q[0] * (0.25 * q[0] * q[0] - q[1]);
	b1 = q[1] - 0.375 * q[0] * q[0];
	res = solve_p4de(x, b1, c1, d1);
	add_solve_quartic_4(x, q[0], res);
	if (res > 0)
	{
		x[0] = n4step(x[0], q);
		x[1] = n4step(x[1], q);
	}
	if (res > 2)
	{
		x[2] = n4step(x[2], q);
		x[3] = n4step(x[3], q);
	}
	return (res);
}
