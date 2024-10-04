/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/04 17:50:43 by pajimene         ###   ########.fr       */
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
	if (!ft_wall_collision(p->pos.x + p->dir.x * 0.2, p->pos.y, data))
		p->pos.x += p->dir.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->dir.y * 0.2, data))
		p->pos.y += p->dir.y * 0.1;
}

void ft_move_down(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->dir.x * 0.2, p->pos.y, data))
		p->pos.x -= p->dir.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->dir.y * 0.2, data))
		p->pos.y -= p->dir.y * 0.1;
}

void ft_move_left(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x - p->plane.x * 0.2, p->pos.y, data))
		p->pos.x -= p->plane.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y - p->plane.y * 0.2, data))
		p->pos.y -= p->plane.y * 0.1;
}

void ft_move_right(t_player *p, t_data *data)
{
	if (!ft_wall_collision(p->pos.x + p->plane.x * 0.2, p->pos.y, data))
		p->pos.x += p->plane.x * 0.1;
	if (!ft_wall_collision(p->pos.x, p->pos.y + p->plane.y * 0.2, data))
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
		ft_move_down(p, data);
	else if (keysym == XK_d)
		ft_move_right(p, data);
	else if (keysym == XK_a)
		ft_move_left(p, data);
	else if (keysym == XK_Right)
		ft_rotate(p, p->angle);
	else if (keysym == XK_Left)
		ft_rotate(p, -p->angle);
	else if (keysym == XK_h)
		p->hide_mouse *= -1;
	return (ft_render_map(data));
}

void	ft_trap_mouse(int x, int y, t_data *data)
{
	if (x > WIDTH - 10)
	{
		x = 10;
		mlx_mouse_move(data->mlx->mlx_con, data->mlx->mlx_win, x, y);
	}
	if (x < 10)
	{
		x = WIDTH - 10;
		mlx_mouse_move(data->mlx->mlx_con, data->mlx->mlx_win, x, y);
	}
}

int	ft_mouse_track(int x, int y, t_data *data)
{
	int	old_x;
	t_player *p;

	(void)y;
	p = data->p;
	if (p->hide_mouse == -1)
		mlx_mouse_hide(data->mlx->mlx_con, data->mlx->mlx_win);
	if (p->hide_mouse == 1)
		mlx_mouse_show(data->mlx->mlx_con, data->mlx->mlx_win);
	ft_trap_mouse(x, y, data);
	old_x = p->mouse.x;
	if (x == old_x)
		return (0);
	if (x > old_x)
		ft_rotate(p, p->angle / 2);
	if (x < old_x)
		ft_rotate(p, -p->angle / 2);
	p->mouse.x = x;
	return (ft_render_map(data));
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
