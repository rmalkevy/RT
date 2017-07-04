/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 14:02:00 by mrassokh          #+#    #+#             */
/*   Updated: 2017/06/05 14:45:59 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		fill_cam(t_camera *camera, char *dots)
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
		if ((space = ft_strchr(split[i - 1], ' ')) ||
						(space = ft_strchr(split[i - 1], '\t')))
		{
			tmp = ft_strsub(split[i - 1], 0, space - split[i - 1]);
			name = ft_strtrim(tmp);
			free(tmp);
			parse_pos(&(camera->position), name, space);
			free(name);
		}
		free(split[i - 1]);
	}
	free(split);
}

void		parse_object_helper(char *name, t_params *par, char *dots)
{
	if (!ft_strcmp(name, "back_color"))
		parse_color(&par->env.back, dots + 1);
	else if (!ft_strcmp(name, "sepia"))
		par->env.sepia = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "black_and_white"))
		par->env.black_and_white = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "threads_quantity"))
	{
		if (!(par->threads_quantity = abs(ft_atoi(dots + 1))))
			par->threads_quantity = 1;
	}
	else if (!ft_strcmp(name, "anti_aliasing"))
		par->env.anti_aliasing = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "CAMERA"))
		fill_cam(&(par->camera), dots);
	else if (!ft_strcmp(name, "contrast"))
		fill_contrast(par, dots + 1);
	else if (!ft_strcmp(name, "negative"))
		par->env.negative = abs(ft_atoi(dots + 1));
	else
		fill_obj(name, par, dots);
}

void		parse_object(char *name, t_params *par, char *dots)
{
	if (!ft_strcmp(name, "WIN_X"))
	{
		if ((par->width = ft_atoi(dots + 1)) < 1)
			error_validate(3);
	}
	else if (!ft_strcmp(name, "WIN_Y"))
	{
		if ((par->height = ft_atoi(dots + 1)) < 1)
			error_validate(3);
	}
	else if (!ft_strcmp(name, "refraction_depth"))
		par->env.refraction_depth = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "reflection_depth"))
		par->env.reflection_depth = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "glares_present"))
		par->env.glares_present = abs(ft_atoi(dots + 1));
	else if (!ft_strcmp(name, "shades_present"))
		par->env.shades_present = abs(ft_atoi(dots + 1));
	else
		parse_object_helper(name, par, dots);
}

void		fill_objects(char **split, t_params *par)
{
	int		i;
	int		k;
	char	*dots;
	char	*tmp;
	char	*name;

	i = 0;
	k = 0;
	dots = NULL;
	while (split[i++])
	{
		dots = ft_strchr(split[i - 1], ':');
		if (!dots)
			error_validate(2);
		tmp = ft_strsub(split[i - 1], 0, dots - split[i - 1]);
		name = ft_strtrim(tmp);
		free(tmp);
		parse_object(name, par, dots);
		free(name);
		free(split[i - 1]);
	}
}

void		read_file(char *file, t_params *par)
{
	t_read		parse;

	ft_bzero(parse.buf, BS + 1);
	parse.str = ft_strnew(0);
	if (!((parse.fd = open(file, O_RDONLY)) >= 0))
		error(errno);
	while ((parse.r = read(parse.fd, parse.buf, BS)))
	{
		if (parse.r == -1)
			error(errno);
		parse.tmp = parse.str;
		parse.str = ft_strjoin(parse.str, parse.buf);
		ft_bzero(parse.buf, BS + 1);
		free(parse.tmp);
	}
	validate_str(parse.str);
	parse.split = ft_strsplit(parse.str, ';');
	free(parse.str);
	set_camera(&(par->camera));
	fill_objects(parse.split, par);
	validate_env(&par->env);
	close(parse.fd);
	free(parse.split);
}
