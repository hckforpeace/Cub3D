/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:24:10 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/28 20:21:09 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calc_door_dist(t_data *data, t_player *p)
{
	int	i;

	i = 0;
	while (i < data->file->door_count)
	{
		data->door[i].dist = pow(p->pos.x - data->door[i].pos.x, 2) + \
			pow(p->pos.y - data->door[i].pos.y, 2);
		i++;
	}
}

static void	ft_calc_sprite_dist(t_data *data, t_player *p)
{
	int	i;

	i = 0;
	while (i < data->file->sprite_count)
	{
		data->sprite[i].dist = pow(p->pos.x - data->sprite[i].pos.x, 2) + \
			pow(p->pos.y - data->sprite[i].pos.y, 2);
		i++;
	}
}

void	ft_sort_sprites_by_dist(t_data *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	ft_calc_sprite_dist(data,  data->p);
	i = 0;
	while (i < data->file->sprite_count)
	{
		j = 0;
		while (j < data->file->sprite_count - 1)
		{
			if (data->sprite[j].dist < data->sprite[j + 1].dist)
			{
				tmp = data->sprite[j];
				data->sprite[j] = data->sprite[j + 1];
				data->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_doors_by_dist(t_data *data)
{
	int			i;
	int			j;
	t_door		tmp;

	ft_calc_door_dist(data, data->p);
	i = 0;
	while (i < data->file->door_count)
	{
		j = 0;
		while (j < data->file->door_count - 1)
		{
			if (data->door[j].dist < data->door[j + 1].dist)
			{
				tmp = data->door[j];
				data->door[j] = data->door[j + 1];
				data->door[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
