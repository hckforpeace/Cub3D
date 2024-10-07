/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:32:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/07 14:59:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_render_map(t_data *data)
{
	ft_draw_background(data);
	ft_raycast(data->ray, data->p, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	return (0);
}

void	ft_draw_vertical(int x, t_point y_vertical, int color, t_data *data)
{
	while (y_vertical.x <= y_vertical.y)
	{
		ft_mlx_pixel_put(data->img, x, y_vertical.x, color);
		y_vertical.x++;
	}
}

void	ft_draw_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y <= HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ft_mlx_pixel_put(data->img, x, y, data->p->ceiling_col);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ft_mlx_pixel_put(data->img, x, y, data->p->floor_col);
			x++;
		}
		y++;
	}
}
