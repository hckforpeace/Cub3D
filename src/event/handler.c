/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/28 21:56:31 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update_motion(t_data *data, t_player *p)
{
	if (p->move_up)
		ft_move_up(p, data);
	if (p->move_down)
		ft_move_down(p, data);
	if (p->move_right)
		ft_move_right(p, data);
	if (p->move_left)
		ft_move_left(p, data);
	if (p->rotate_right)
		ft_rotate(p, p->angle);
	if (p->rotate_left)
		ft_rotate(p, -p->angle);
	if (p->open_door)
		ft_open_door(data);
	if (p->close_door)
		ft_close_door(data);
	if (p->speed_up)
		ft_speed_up(p);
}

int	ft_key_press(int keycode, t_data *data)
{
	t_player	*p;

	p = data->p;
	if (keycode == XK_Escape)
		ft_close(data);
	if (keycode == XK_w)
		p->move_up = 1;
	else if (keycode == XK_s)
		p->move_down = 1;
	else if (keycode == XK_d)
		p->move_right = 1;
	else if (keycode == XK_a)
		p->move_left = 1;
	else if (keycode == XK_Right)
		p->rotate_right = 1;
	else if (keycode == XK_Left)
		p->rotate_left = 1;
	else if (keycode == XK_o)
		p->open_door = 1;
	else if (keycode == XK_c)
		p->close_door = 1;
	else if (keycode == XK_Shift_L)
		p->speed_up = 1;
	else if (keycode == XK_h)
		p->hide_mouse *= -1;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	t_player	*p;

	p = data->p;
	if (keycode == XK_w)
		p->move_up = 0;
	else if (keycode == XK_s)
		p->move_down = 0;
	else if (keycode == XK_d)
		p->move_right = 0;
	else if (keycode == XK_a)
		p->move_left = 0;
	else if (keycode == XK_Right)
		p->rotate_right = 0;
	else if (keycode == XK_Left)
		p->rotate_left = 0;
	else if (keycode == XK_o)
		p->open_door = 0;
	else if (keycode == XK_c)
		p->close_door = 0;
	else if (keycode == XK_Shift_L)
	{
		p->speed = 0.06;
		p->speed_up = 0;
	}
	return (0);
}

static void	ft_trap_mouse(int x, int y, t_data *data)
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
	// if (y > HEIGHT - 10)
	// {
	// 	y = 10;
	// 	mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	// }
	// if (y < 10)
	// {
	// 	y = HEIGHT - 10;
	// 	mlx_mouse_move(data->mlx, data->mlx_win, x, y);
	// }
}

int	ft_mouse(int x, int y, t_data *data)
{
	t_player	*p;
	int			old_x;

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
		ft_rotate(p, p->angle / 1.2);
	if (x < old_x)
		ft_rotate(p, -p->angle / 1.2);
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

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	free(data);
	exit(0);
}
