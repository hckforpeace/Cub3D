/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:13:06 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/07 12:14:35 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(t_player *p, double angle)
{
	double	tmp_x;

	tmp_x = p->dir.x;
	p->dir.x = p->dir.x * cos(angle) - p->dir.y * sin(angle);
	p->dir.y = tmp_x * sin(angle) + p->dir.y * cos(angle);
	tmp_x = p->plane.x;
	p->plane.x = p->plane.x * cos(angle) - p->plane.y * sin(angle);
	p->plane.y = tmp_x * sin(angle) + p->plane.y * cos(angle);
}

void	ft_move_up(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->dir.x * 0.2, p->pos.y, data))
		p->pos.x += p->dir.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->dir.y * 0.2, data))
		p->pos.y += p->dir.y * 0.1;
}

void	ft_move_down(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->dir.x * 0.2, p->pos.y, data))
		p->pos.x -= p->dir.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->dir.y * 0.2, data))
		p->pos.y -= p->dir.y * 0.1;
}

void	ft_move_left(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->plane.x * 0.2, p->pos.y, data))
		p->pos.x -= p->plane.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->plane.y * 0.2, data))
		p->pos.y -= p->plane.y * 0.1;
}

void	ft_move_right(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->plane.x * 0.2, p->pos.y, data))
		p->pos.x += p->plane.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->plane.y * 0.2, data))
		p->pos.y += p->plane.y * 0.1;
}
