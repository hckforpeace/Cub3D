/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:27 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/28 21:50:36 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_count_sprites_doors(t_file *file, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'X')
				file->sprite_count++;
			if (file->map[i][j] == 'D')
				file->door_count++;
			j++;
		}
		i++;
	}
	data->sprite = ft_calloc(file->sprite_count + 1, sizeof(t_sprite));
	if (!data->sprite)
		return ;
	data->door = ft_calloc(file->door_count + 1, sizeof(t_door));
	if (!data->door)
		return ;
}

void	ft_parse_sprites_doors(t_file *file, t_data *data)
{
	int	i;
	int	j;
	int	s;
	int	d;

	ft_count_sprites_doors(file, data);
	i = 0;
	s = 0;
	d = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'X')
			{
				data->sprite[s].pos.x = j + 0.5;
				data->sprite[s].pos.y = i + 0.5;
				s++;
			}
			if (file->map[i][j] == 'D')
			{
				data->door[d].pos.x = j + 0.5;
				data->door[d].pos.y = i + 0.5;
				data->door[d].status = CLOSE;
				data->door[d].door_id = DOOR_0;
				ft_bzero(&data->door[d].ray, sizeof(t_raycast));
				d++;
			}
			j++;
		}
		i++;
	}
}
