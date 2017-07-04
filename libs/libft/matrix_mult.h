/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:56:09 by mrassokh          #+#    #+#             */
/*   Updated: 2017/02/11 09:58:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_MULT_H
# define MATRIX_MULT_H
# include <stdlib.h>
# include <math.h>

typedef struct	s_matr
{
	float		**mt;
	size_t		w;
	size_t		h;
}				t_matr;

t_matr			*matrix_mult(t_matr *m1, t_matr *m2);
t_matr			*allocate_matrix(size_t h, size_t w);
float			new_chamber(int i, int j, t_matr *m1, t_matr *m2);
t_matr			*create_single_m(size_t size);
t_matr			*create_masht_m(float x, float y, float z, float s);
t_matr			*create_shift_m(float x_shift, float y_shift, float z_shift);
t_matr			*create_t_matr(float fi_x, float fi_y, float fi_z);
t_matr			*rotate_x(float fi);
t_matr			*rotate_y(float fi);
t_matr			*rotate_z(float fi);
t_matr			*orto_zy(int n);
t_matr			*orto_xy(int n);
t_matr			*orto_xz(int n);

int				create_masht_m_a(t_matr *res, float x, float y, float z);
int				create_single_m_a(t_matr *res, size_t size);
int				create_shift_m_a(t_matr *res,
					float x_shift, float y_shift, float z_shift);
int				rotate_x_a(t_matr *res, float fi);
int				rotate_y_a(t_matr *res, float fi);
int				rotate_z_a(t_matr *res, float fi);
int				matrix_mult_a(t_matr *res, t_matr *m1, t_matr *m2);
void			matrix_clear(t_matr *m);

#endif
