/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:39:41 by mrassokh          #+#    #+#             */
/*   Updated: 2017/05/31 11:12:14 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		fill_light_point(t_light_point *light, char *dots)
{
	char	**split;
	int		i;
	char	*space;
	char	*name;
	char	*tmp;

	i = 0;
	split = ft_strsplit(dots, '\n');
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		space = ft_strchr(split[i - 1], ' ');
		if (space)
		{
			tmp = ft_strsub(split[i - 1], 0, space - split[i - 1]);
			name = ft_strtrim(tmp);
			free(tmp);
			point_light_processing(light, name, space);
			free(name);
		}
		free(split[i - 1]);
	}
	free(split);
}

void		fill_par_light(t_parallel_light *par_light, char *dots)
{
	char	**split;
	int		i;
	char	*space;
	char	*name;
	char	*tmp;

	i = 0;
	split = ft_strsplit(dots, '\n');
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		space = ft_strchr(split[i - 1], ' ');
		if (space)
		{
			tmp = ft_strsub(split[i - 1], 0, space - split[i - 1]);
			name = ft_strtrim(tmp);
			free(tmp);
			par_light_processing(par_light, name, space);
			free(name);
		}
		free(split[i - 1]);
	}
	free(split);
}

void		fill_dir_light(t_direct_light *dir_light, char *dots)
{
	char	**split;
	int		i;
	char	*space;
	char	*name;
	char	*tmp;

	i = 0;
	split = ft_strsplit(dots, '\n');
	while (split[i++])
	{
		if (!validate_split(split[i - 1], split, i - 1))
			break ;
		space = ft_strchr(split[i - 1], ' ');
		if (space)
		{
			tmp = ft_strsub(split[i - 1], 0, space - split[i - 1]);
			name = ft_strtrim(tmp);
			free(tmp);
			dir_light_processing(dir_light, name, space);
			free(name);
		}
		free(split[i - 1]);
	}
	free(split);
}
