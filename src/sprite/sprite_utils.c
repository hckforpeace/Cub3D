/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:24:10 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 18:05:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calc_sprite_dist(t_file *fdata, t_player *p)
{
	int	i;

	i = 0;
	while (i < fdata->sprite_count)
	{
		fdata->sprite[i].dist = pow(p->pos.x - fdata->sprite[i].pos.x, 2) + \
			pow(p->pos.y - fdata->sprite[i].pos.y, 2);
		i++;
	}
}

void	ft_sort_sprites_by_dist(t_data *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	ft_calc_sprite_dist(data->fdata, data->p);
	i = 0;
	while (i < data->fdata->sprite_count)
	{
		j = 0;
		while (j < data->fdata->sprite_count - 1)
		{
			if (data->fdata->sprite[j].dist < data->fdata->sprite[j + 1].dist)
			{
				tmp = data->fdata->sprite[j];
				data->fdata->sprite[j] = data->fdata->sprite[j + 1];
				data->fdata->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
