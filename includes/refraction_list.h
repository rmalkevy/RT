/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandreyc <kandreyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:21:51 by kandreyc          #+#    #+#             */
/*   Updated: 2017/06/04 23:09:21 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFRACTION_LIST_H
# define REFRACTION_LIST_H

# include <stdlib.h>

# define TRUE	1
# define FALSE	0
# define LIST t_refr_lst **head_lst

typedef struct			s_refr_lst
{
	int					id;
	double				refr_coeff;
	double				include;
	double				eff_refr;
	struct s_refr_lst	*next;
}						t_refr_lst;

t_refr_lst				*refr_lst__new_elem(int id, double refr_coeff);
t_refr_lst				*refr_lst__get_elem(t_refr_lst **head_lst, int id);
t_refr_lst				*refr_lst__get_prev_elem(t_refr_lst **head_lst, int id);
int						refr_lst__add_elem(t_refr_lst **head_lst, int id,
		double refr_coeff);
int						refr_lst__del_elem(t_refr_lst **head_lst, int id);
t_refr_lst				*refr_lst__copy_lst(t_refr_lst **head_lst);
void					clear_refracted(t_refr_lst *begin);
void					find_end_list(t_refr_lst **begin, t_refr_lst **end);

#endif
