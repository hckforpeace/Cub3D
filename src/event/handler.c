/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/03 17:41:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_rotate(t_player *p, double angle)
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
	if (!ft_wall_collision(p->pos.y, p->pos.x + p->dir.x * 0.1, data))
		p->pos.x += p->dir.x * 0.1;
	if (!ft_wall_collision(p->pos.y + p->dir.y * 0.1, p->pos.x, data))
		p->pos.y += p->dir.y * 0.1;
}

void ft_move_down(t_player *p)
{
	p->pos.x -= p->dir.x * 0.1;
	p->pos.y -= p->dir.y * 0.1;
}

void ft_move_left(t_player *p)
{
	p->pos.x -= p->plane.x * 0.1;
	p->pos.y -= p->plane.y * 0.1;
}

void ft_move_right(t_player *p)
{
	p->pos.x += p->plane.x * 0.1;
	p->pos.y += p->plane.y * 0.1;
}

int ft_key(int keysym, t_data *data)
{
	t_player *p;

	p = data->p;
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_w)
		ft_move_up(p, data);
	else if (keysym == XK_s)
		ft_move_down(p);
	else if (keysym == XK_d)
		ft_move_right(p);
	else if (keysym == XK_a)
		ft_move_left(p);
	else if (keysym == XK_Right)
		ft_rotate(p, p->angle);
	else if (keysym == XK_Left)
		ft_rotate(p, -p->angle);
	ft_render_map(data);
	return (0);
}

int ft_close(t_data *data)
{
	t_mlx *mlx;

	mlx = data->mlx;
	mlx_destroy_image(mlx->mlx_con, mlx->img);
	mlx_destroy_window(mlx->mlx_con, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_con);
	free(mlx->mlx_con);
	free(data->mlx);
	free(data);
	exit(0);
}
