/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 14:53:36 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}

static void ft_trap_mouse(int x, int y, t_data *data)
{
	if (x > WIDTH - 10)
	{
		x = 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (x < 10)
	{
		x = WIDTH - 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (y > HEIGHT - 10)
	{
		y = 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
	if (y < 10)
	{
		y = HEIGHT - 10;
		mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	}
}

int ft_mouse_tk(int x, int y, t_data *data)
{
	int old_x;
	//int	old_y;
	t_player *p;

	(void)y;
	p = data->p;
	if (p->hide_mouse == -1)
		mlx_mouse_hide(data->mlx, data->mlx_win);
	if (p->hide_mouse == 1)
		mlx_mouse_show(data->mlx, data->mlx_win);
	ft_trap_mouse(x, y, data);
	old_x = p->mouse.x;
	if (x == old_x)
		return (0);
	if (x > old_x)
		ft_rotate(p, p->angle / 2);
	if (x < old_x)
		ft_rotate(p, -p->angle / 2);
	p->mouse.x = x;
	// old_y = p->mouse.y;
	// if (y == old_y)
	// 	return (0);
	// if (y > old_y)
	// 	ft_rotate(p, p->angle / 2);
	// if (y < old_y)
	// 	ft_rotate(p, -p->angle / 2);
	// p->mouse.y = y;
	return (0);
}

int ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	free(data);
	exit(0);
}
