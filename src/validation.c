/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:31:10 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/03 10:50:14 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		validate_env(t_env *env)
{
	if (env->glares_present > 1)
		env->glares_present = 1;
	if (env->shades_present > 1)
		env->shades_present = 1;
	if (env->anti_aliasing == 0)
		env->anti_aliasing = 1;
}

int			compare_name(char *name, char **split, int i)
{
	if (!ft_strcmp(name, "SPHERE") || !ft_strcmp(name, "PLAIN") ||
		!ft_strcmp(name, "CYLINDER") || !ft_strcmp(name, "CONE")
		|| !ft_strcmp(name, "LIGHT_POINT") || !ft_strcmp(name, "LIGHT_DIR")
		|| !ft_strcmp(name, "LIGHT_PAR") || !ft_strcmp(name, "CAMERA"))
	{
		ft_putendl("You try to add new object ");
		ft_putendl(name);
		ft_putendl("in incorrect way. May be you forgot close previous object "
					"by ;");
		free(name);
		while (split[i++])
			free(split[i - 1]);
		return (0);
	}
	return (1);
}

void		validate_str(char *str)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (str[i++])
		if (str[i - 1] == ';')
			count++;
	if (!count || str[i - 2] != ';')
		error_validate(1);
}

int			validate_split(char *str, char **split, int i)
{
	char	*name;
	char	*dots;
	char	*tmp;

	dots = NULL;
	dots = ft_strchr(str, ':');
	if (dots)
	{
		tmp = ft_strsub(str, 0, dots - str);
		name = ft_strtrim(tmp);
		free(tmp);
	}
	else
		name = ft_strtrim(str);
	if (!compare_name(name, split, i))
		return (0);
	free(name);
	return (1);
}
