/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_save_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:31:15 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 15:32:49 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// the (char **) will contain an array of a size 
int	save_map(int len, t_file *fdata, t_list *list)
{
	int	i;

	fdata->map = (char **)malloc(sizeof(char *) * (len + 1));
	fdata->map[len] = NULL;
	i = 0;
	while (i < len)
	{
		fdata->map[i] = (char *)malloc(sizeof(char)
				* (ft_strlen((char *)list->content) + 1));
		if (!fdata->map[i])
			return (i);
		ft_strcpy(fdata->map[i], (char *)list->content);
		list = list->next;
		i++;
	}
	return (-1);
}
