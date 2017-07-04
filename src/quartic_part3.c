/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic_part3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	c_sqrt(double x, double y, double *a, double *b)
{
	double r;

	r = sqrt(x * x + y * y);
	if (y == 0)
	{
		r = sqrt(r);
		if (x >= 0)
		{
			*a = r;
			*b = 0;
		}
		else
		{
			*a = 0;
			*b = r;
		}
	}
	else
	{
		*a = sqrt(0.5 * (x + r));
		*b = 0.5 * y / *a;
	}
}

int		part1_solve_p4bi(double *x, double ddd, double b)
{
	double sd;
	double x1;
	double x2;

	sd = sqrt(ddd);
	x1 = (-b + sd) / 2;
	x2 = (-b - sd) / 2;
	x[1] = sqrt(fabs(x1));
	x[3] = sqrt(fabs(x2));
	x[0] = -x[1];
	x[2] = 0;
	if (x2 >= 0)
	{
		x[0] = -x[1];
		x[2] = -x[3];
		return (4);
	}
	if (x1 < 0)
	{
		x[0] = 0;
		x[2] = 0;
		return (0);
	}
	return (2);
}

int		solve_p4bi(double *x, double b, double d)
{
	double ddd;
	double sd2;

	ddd = b * b - 4 * d;
	if (ddd >= 0)
		return (part1_solve_p4bi(x, ddd, b));
	else
	{
		sd2 = 0.5 * sqrt(-ddd);
		c_sqrt(-0.5 * b, sd2, &x[0], &x[1]);
		c_sqrt(-0.5 * b, -sd2, &x[2], &x[3]);
		return (0);
	}
}
