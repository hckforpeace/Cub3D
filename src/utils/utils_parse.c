/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:44:28 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 00:24:58 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	takes the content in parameter 
	splits it on the space
	checks there are exactly 2 words in the array 
	and free's the array and return 1 in case of success
	or free's array and returns 0 in case of failure 
*/
int	ft_istexture(char *str)
{
	char **info;

	info = ft_split(str, ' ');
	if (!info)
		return (0);
	if (!*info || ft_tablen(info) != 2 )
		return (clear_wordar(info), 0);
	if (!ft_strcmp(*info, "NO") || !ft_strcmp(*info, "SO")
		|| !ft_strcmp(*info, "WE") || !ft_strcmp(*info, "EA"))
		return (clear_wordar(info), 1);
	return (clear_wordar(info), 0);
}

int	ft_iscolor(char *str)
{
	char **info;

	info = ft_split(str, ' ');
	if (!info)
		return (clear_wordar(info), 0);
	if (!*info || ft_tablen(info) != 2 )
		return (clear_wordar(info), 0);
	if (!ft_strcmp(*info, "C") || !ft_strcmp(*info, "F"))
		return (clear_wordar(info), 1);
	return (clear_wordar(info), 0);
}

// TODO test it
int	ft_isemptyline(char *str)
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

t_list	*save_texture(t_list *list, t_data *data)
{
	int		i;
	char	**info;

	i = 0;
	while (i < 4)
	{
		if (!list || ft_isemptyline((char *)list->content))
			return (NULL);
		if (!ft_istexture((char *)list->content))
			return (NULL);
		info = ft_split((char *)list->content, ' ');
		parse_savetxture(info, data);
		clear_wordar(info);
		i++;
		list = list->next;
	}
	return (list);
}

t_list	*save_color(t_list *list, t_data *data)
{
	int		i;
	char	**info;

	i = 0;
	while (i < 2)
	{
		if (!list || ft_isemptyline((char *)list->content))
			return (NULL);
		if (!ft_iscolor((char *)list->content))
			return (NULL);
		info = ft_split((char *)list->content, ' ');
		if (!parse_savecolor(info, data))
			return (NULL);
		clear_wordar(info);
		i++;
		list = list->next;
	}
	return (list);
}
