/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:20:29 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/03 14:47:46 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LIB_H
# define VECTOR_LIB_H

# include <math.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

void				intersection_point(t_vector *a, t_vector *b, double k,
																t_vector *v);
void				vector_cos(t_vector *a, t_vector *b, double *value);
void				vector_mod(t_vector *a, double *b);
void				vector_set(double x, double y, double z, t_vector *a);
void				vector_unit(t_vector *a, t_vector *b);
void				vector_sub(t_vector *a, t_vector *b, t_vector *res);
t_vector			vector_mult2(int num, t_vector *v1, t_vector *v2);
void				vector_mult(t_vector *a, double k, t_vector *result);
void				vector_dot(t_vector *a, t_vector *b, double *scalar);
void				vector_sum(t_vector *a, t_vector *b, t_vector *c);
void				vector_cross(t_vector *a, t_vector *b, t_vector *c);

#endif
