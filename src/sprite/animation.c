/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:46 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/29 11:42:25 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_animate_sprite(t_data *data)
{
	static int	fps = 0;

	if (fps < 50)
		data->sprite->sprite_id = SPRITE_0;
	else if (fps < 55)
		data->sprite->sprite_id = SPRITE_1;
	else if (fps < 60)
		data->sprite->sprite_id = SPRITE_2;
	else if (fps < 65)
		data->sprite->sprite_id = SPRITE_3;
	else if (fps < 70)
		data->sprite->sprite_id = SPRITE_4;
	else if (fps < 75)
		data->sprite->sprite_id = SPRITE_5;
	else if (fps < 80)
		data->sprite->sprite_id = SPRITE_6;
	else if (fps < 85)
		data->sprite->sprite_id = SPRITE_7;
	else if (fps < 90)
		data->sprite->sprite_id = SPRITE_8;
	else if (fps < 140)
		data->sprite->sprite_id = SPRITE_9;
	else if (fps < 145)
		data->sprite->sprite_id = SPRITE_8;
	else if (fps < 150)
		data->sprite->sprite_id = SPRITE_7;
	else if (fps < 155)
		data->sprite->sprite_id = SPRITE_6;
	else if (fps < 160)
		data->sprite->sprite_id = SPRITE_5;
	else if (fps < 165)
		data->sprite->sprite_id = SPRITE_4;
	else if (fps < 170)
		data->sprite->sprite_id = SPRITE_3;
	else if (fps < 175)
		data->sprite->sprite_id = SPRITE_2;
	else if (fps < 180)
		data->sprite->sprite_id = SPRITE_1;
	else
		fps = 0;
	fps++;
}

void	ft_animate_open_door(t_data *data)
{
	static int	fps = 0;

	if (fps < 6)
		data->door[data->file->door_count - 1].door_id = DOOR_0;
	else if (fps < 12)
		data->door[data->file->door_count - 1].door_id = DOOR_1;
	else if (fps < 18)
		data->door[data->file->door_count - 1].door_id = DOOR_2;
	else if (fps < 24)
		data->door[data->file->door_count - 1].door_id = DOOR_3;
	else if (fps < 30)
		data->door[data->file->door_count - 1].door_id = DOOR_4;
	else if (fps < 36)
		data->door[data->file->door_count - 1].door_id = DOOR_5;
	else if (fps < 42)
		data->door[data->file->door_count - 1].door_id = DOOR_6;
	else
	{
		data->door[data->file->door_count - 1].door_id = DOOR_7;
		data->door[data->file->door_count - 1].status = OPEN;
		fps = 0;
	}
	fps++;
}

void	ft_animate_close_door(t_data *data)
{
	static int	fps = 0;

	if (fps < 6)
		data->door[data->file->door_count - 1].door_id = DOOR_7;
	else if (fps < 12)
		data->door[data->file->door_count - 1].door_id = DOOR_6;
	else if (fps < 18)
		data->door[data->file->door_count - 1].door_id = DOOR_5;
	else if (fps < 24)
		data->door[data->file->door_count - 1].door_id = DOOR_4;
	else if (fps < 30)
		data->door[data->file->door_count - 1].door_id = DOOR_3;
	else if (fps < 36)
		data->door[data->file->door_count - 1].door_id = DOOR_2;
	else if (fps < 42)
		data->door[data->file->door_count - 1].door_id = DOOR_1;
	else
	{
		data->door[data->file->door_count - 1].door_id = DOOR_0;
		data->door[data->file->door_count - 1].status = CLOSE;
		fps = 0;
	}
	fps++;
}
