/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:29:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/29 17:12:18 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_near_door(t_data *data)
{
	if (data->door[data->file->door_count - 1].dist <= 9)
	{
		
		return (1);
	}
	return (0);
}

int	ft_door_status(t_data *data, int y, int x)
{
	int	i;

	i = data->file->door_count - 1;
	while (i >= 0)
	{
		if (((int)data->door[i].pos.x == x) && ((int)data->door[i].pos.y == y))
			return (data->door[i].status);
		i--;
	}
	return (0);
}
