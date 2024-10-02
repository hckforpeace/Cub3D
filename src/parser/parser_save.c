/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:16:15 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 15:39:08 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_savetxture(char **info, t_file *fdata)
{
	if (!ft_strcmp(info[0], "NO"))
	{
		if (fdata->NO)
			free(fdata->NO);
		fdata->NO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "SO"))
	{
		if (fdata->SO)
			free(fdata->SO);
		fdata->SO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "WE"))
	{
		if (fdata->WE)
			free(fdata->WE);
		fdata->WE = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
	if (!ft_strcmp(info[0], "EA"))
	{
		if (fdata->EA)
			free(fdata->EA);
		fdata->EA = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	}
}

static void	save_color(t_file *fdata, int color, int i, char **info)
{
	if (!ft_strcmp(info[0], "C"))
		fdata->crgb[i] = color;
	else
		fdata->frgb[i] = color;
}

int	parse_savecolor(char **info, t_file *fdata)
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
		save_color(fdata, ft_atoi(rgb[i]), i, info);
	}
	clear_wordar(rgb);
	return (1);
}
