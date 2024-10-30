/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 18:43:40 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_direction_aux(t_player *p)
{
	if (p->direction == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
	if (p->direction == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = -0.66;
	}
}

static void	ft_set_direction(t_player *p)
{
	if (p->direction == 'N')
	{
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = 0.66;
		p->plane.y = 0;
	}
	if (p->direction == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
		p->plane.x = -0.66;
		p->plane.y = 0;
	}
	ft_set_direction_aux(p);
}

void	ft_player_init(t_data *data)
{
	t_player	*p;

	p = data->p;
	p->pos.x = data->file->start[1] + 0.5;
	p->pos.y = data->file->start[0] + 0.5;
	p->ceiling_col = ft_rgb_to_hex(data->file->crgb);
	p->floor_col = ft_rgb_to_hex(data->file->frgb);
	p->angle = 0.035;
	p->speed = 0.15;
	p->pitch = 0;
	p->move_down = 0;
	p->move_up = 0;
	p->move_left = 0;
	p->move_right = 0;
	p->rotate_left = 0;
	p->rotate_right = 0;
	p->rotate_down = 0;
	p->rotate_up = 0;
	p->open_door = 0;
	p->close_door = 0;
	p->speed_up = 0;
	p->jump = 0;
	p->direction = data->file->orientation;
	p->mouse.x = WIDTH / 2;
	p->mouse.y = HEIGHT / 2;
	ft_set_direction(p);
}
