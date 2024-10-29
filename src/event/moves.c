/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:13:06 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/29 12:39:51 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_speed_up(t_player *p)
{
	p->speed = 0.18;
}

void ft_rotate(t_player *p, double angle)
{
	double tmp_x;

	tmp_x = p->dir.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = tmp_x * sin(angle) + p->dir.y * cos(angle);
	tmp_x = p->plane.x;
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = tmp_x * sin(angle) + p->plane.y * cos(angle);
}

void ft_move_up(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->dir.x * 0.3, p->pos.y, data))
		p->pos.x += p->dir.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->dir.y * 0.3, data))
		p->pos.y += p->dir.y * p->speed;
}

void ft_move_down(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->dir.x * 0.3, p->pos.y, data))
		p->pos.x -= p->dir.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->dir.y * 0.3, data))
		p->pos.y -= p->dir.y * p->speed;
}

void ft_move_left(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->plane.x * 0.3, p->pos.y, data))
		p->pos.x -= p->plane.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->plane.y * 0.3, data))
		p->pos.y -= p->plane.y * p->speed;
}

void ft_move_right(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->plane.x * 0.3, p->pos.y, data))
		p->pos.x += p->plane.x * p->speed;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->plane.y * 0.3, data))
		p->pos.y += p->plane.y * p->speed;
}

void ft_open_door(t_data *data)
{
	if (data->door[data->file->door_count - 1].status == CLOSE && ft_is_near_door(data))
		data->door[data->file->door_count - 1].status = IS_OPENING;
}

void ft_close_door(t_data *data)
{
	if (data->door[data->file->door_count - 1].status == OPEN && ft_is_near_door(data) && !ft_select_door(data, data->p->pos.y, data->p->pos.x, data->file->door_count - 1))
		data->door[data->file->door_count - 1].status = IS_CLOSING;
}
