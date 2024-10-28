/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:16:15 by pierre            #+#    #+#             */
/*   Updated: 2024/10/28 20:21:09 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_savetxture(char **info, t_file *file)
{
	if (!ft_strcmp(info[0], "NO"))
	{
		if (file->NO)
			free(file->NO);
		file->NO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "SO"))
	{
		if (file->SO)
			free(file->SO);
		file->SO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "WE"))
	{
		if (file->WE)
			free(file->WE);
		file->WE = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "EA"))
	{
		if (file->EA)
			free(file->EA);
		file->EA = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
}

static void	parse_savecolaux(t_file *file, int color, int i, char **info)
{
	if (!ft_strcmp(info[0], "C"))
		file->crgb[i] = color;
	else
		file->frgb[i] = color;
}

int	parse_savecolor(char **info, t_file *file)
{
	char	**rgb;
	int		i;
	int		j;

	if (ft_strcmp(info[0], "C") && ft_strcmp(info[0], "F"))
		return (clear_wordar(info), 0);
	rgb = ft_split(info[1], ',');
	if (ft_tablen(rgb) != 3)
		return (clear_wordar(rgb), clear_wordar(info), 0);
	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while (rgb[i][++j] && (i != 2 && rgb[i][j] != '\n'))
		{
			if (!ft_isalnum(rgb[i][j]))
				return (clear_wordar(rgb), clear_wordar(info), 0);
		}
		if (ft_atoi(rgb[i]) > 255)
			return (clear_wordar(rgb), clear_wordar(info), 0);
		parse_savecolaux(file, ft_atoi(rgb[i]), i, info);
	}
	clear_wordar(rgb);
	return (1);
}
