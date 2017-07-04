/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#define SWAP(a, b) { t = b; b = a; a = t; }

void	dbl_sort3(double *a, double *b, double *c)
{
	double t;

	if (*a > *b)
		SWAP(*a, *b);
	if (*c < *b)
	{
		SWAP(*b, *c);
		if (*a > *b)
			SWAP(*a, *b);
	}
}

int		part1_solve_p4de(double *x, double c)
{
	double sz1;
	double sz2;
	double sz3;

	sz1 = sqrt(x[0]);
	sz2 = sqrt(x[1]);
	sz3 = sqrt(x[2]);
	if (c > 0)
	{
		x[0] = (-sz1 - sz2 - sz3) / 2;
		x[1] = (-sz1 + sz2 + sz3) / 2;
		x[2] = (+sz1 - sz2 + sz3) / 2;
		x[3] = (+sz1 + sz2 - sz3) / 2;
		return (4);
	}
	x[0] = (-sz1 - sz2 + sz3) / 2;
	x[1] = (-sz1 + sz2 - sz3) / 2;
	x[2] = (+sz1 - sz2 - sz3) / 2;
	x[3] = (+sz1 + sz2 + sz3) / 2;
	return (4);
}

int		part2_solve_p4de(double *x, double c)
{
	double sz1;
	double sz2;
	double sz3;

	sz1 = sqrt(-x[0]);
	sz2 = sqrt(-x[1]);
	sz3 = sqrt(+x[2]);
	if (c > 0)
	{
		x[0] = -sz3 / 2;
		x[1] = (sz1 - sz2) / 2;
		x[2] = sz3 / 2;
		x[3] = (-sz1 - sz2) / 2;
		return (0);
	}
	x[0] = sz3 / 2;
	x[1] = (-sz1 + sz2) / 2;
	x[2] = -sz3 / 2;
	x[3] = (sz1 + sz2) / 2;
	return (0);
}

int		part3_solve_p4de(double *x, double c)
{
	double sz1;
	double szr;
	double szi;

	sz1 = sqrt(x[0]);
	c_sqrt(x[1], x[2], &szr, &szi);
	if (c > 0)
	{
		x[0] = -sz1 / 2 - szr;
		x[1] = -sz1 / 2 + szr;
		x[2] = sz1 / 2;
		x[3] = szi;
		return (2);
	}
	x[0] = sz1 / 2 - szr;
	x[1] = sz1 / 2 + szr;
	x[2] = -sz1 / 2;
	x[3] = szi;
	return (2);
}

int		solve_p4de(double *x, double b, double c, double d)
{
	int res3;

	if (fabs(c) < 1e-14 * (fabs(b) + fabs(d)))
		return (solve_p4bi(x, b, d));
	res3 = solve_p3(x, 2 * b, b * b - 4 * d, -c * c);
	if (res3 > 1)
	{
		dbl_sort3(&x[0], &x[1], &x[2]);
		if (x[0] > 0)
			return (part1_solve_p4de(x, c));
		return (part2_solve_p4de(x, c));
	}
	if (x[0] < 0)
		x[0] = 0;
	return (part3_solve_p4de(x, c));
}
