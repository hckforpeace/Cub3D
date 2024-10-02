/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:32:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/02 15:32:38 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_render_map(t_data *data)
{
	printf("coucou\n");
	ft_draw_background(data);
	ft_raycast(data->ray, data->p, data);
	mlx_put_image_to_window(data->mlx->mlx_con, data->mlx->mlx_win,
							data->mlx->img, 0, 0);
}

void ft_draw_vertical(int x, int y_start, int y_end, int color, t_data *data)
{
	while (y_start <= y_end)
	{
		ft_mlx_pixel_put(data->mlx, x, y_start, color);
		y_start++;
	}
}

void ft_draw_background(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y <= HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ft_mlx_pixel_put(data->mlx, x, y, LAVANDE);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			ft_mlx_pixel_put(data->mlx, x, y, MENTHE);
			x++;
		}
		y++;
	}
}
