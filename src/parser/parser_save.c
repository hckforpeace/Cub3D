/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:16:15 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 21:34:29 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_savetxture(char **info, t_data *data)
{
	if (!ft_strcmp(info[0], "NO"))
		data->NO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	if (!ft_strcmp(info[0], "SO"))
		data->SO = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	if (!ft_strcmp(info[0], "WE"))
		data->WE = ft_strndup(info[1], ft_strlen(info[1]) - 1);
	if (!ft_strcmp(info[0], "EA"))
		data->EA = ft_strndup(info[1], ft_strlen(info[1]) - 1);
}

int	parse_savecolor(char **info, t_data *data)
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
		if (!ft_strcmp(info[0], "C"))
			data->crgb[i] = ft_atoi(rgb[i]);
		else
			data->frgb[i] = ft_atoi(rgb[i]);			
	}
	return (1);
}
