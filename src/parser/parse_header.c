/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:22 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/09/30 16:17:20 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// tells you if it's a texture 
static int	ft_istexture(char *str)
{
	char **info;

	info = ft_split(str, ' ');
	if (!*info || ft_tablen(info) != 2 )
		return (clear_wordar(info), 0);
	if (!ft_strcmp(info, "NO") || !ft_strcmp(info, "SO")
		|| !ft_strcmp(info, "WE") || !ft_strcmp(info, "EA"))
		return (clear_wordar(info), 1);
	return (clear_wordar(info), 0);
}

// TODO test it
int	is_empty_line(char *str)
{
	if (!str || !*str)
		return (1);
	while (str)
	{
		if (*str == '\n' || *str == '\0')
			return (1);
		else if (*str == ' ')
			str++;
		else
			return (0);
	}
	return (0);
}

t_list	*save_texture(t_list *list)
{
	int	i;
	char **info;

	i = 0;
	while (i < 4)
	{
		if (!list || is_empty_line((char *)list->content))
			return (NULL);
		info = ft_split((char *)list->content, ' ');
		if (!info || ft_tablen(info) != 2 || !ft_istexture((char *)list->content))
			return (clear_wordar(info), NULL);
		clear_wordar(info);
		// save into the data the path
		i++;
		list = list->next;
	}
	return (list);
}

int	parse_texture_color(t_data *data, t_list* list)
{
	if (ft_istexture(list->content))
	{
		list = save_texture(list);
	}
	else if ()
}
int	parse_header(t_data *data, t_list *list)
{
	if (!list)
		return (/* empty file */0);
	while (is_empty_line((char *)list->content))
		list = list->next;
	if (!list)
		return (/* empty file*/0);
	list = parse_texture_color(data, data->fd_list);
}
