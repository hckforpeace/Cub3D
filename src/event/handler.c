/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/02 19:01:42 by pajimene         ###   ########.fr       */
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

int ft_key(int keysym, t_data *data)
{
	t_player *p;

	p = data->p;
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_w)
	{
		p->pos.x += p->dir.x * 0.1;
		p->pos.y += p->dir.y * 0.1;
	}
	else if (keysym == XK_s)
	{
		p->pos.x -= p->dir.x * 0.1;
		p->pos.y -= p->dir.y * 0.1;
	}
	else if (keysym == XK_d)
	{
		p->pos.x += p->plane.x * 0.1;
		p->pos.y += p->plane.y * 0.1;
	}
	else if (keysym == XK_a)
	{
		p->pos.x -= p->plane.x * 0.1;
		p->pos.y -= p->plane.y * 0.1;
	}
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
