/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:32:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 18:07:28 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_img(t_data *data, t_img *img)
{
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ((void)printf(MLX_IMG));
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
		&img->endian);
}

int	ft_render_map(t_data *data)
{
	ft_animate_sprite(data);
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
		&data->img->line_len, &data->img->endian);
	ft_draw_background(data);
	ft_raycast(data->ray, data->p, data);
	ft_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img, 0, 0);
	return (0);
}

void	ft_draw_circle(t_point center, int radius, int color, t_data *data)
{
	int	x;
	int	y;

	x = center.x - radius;
	while (x <= center.x + radius)
	{
		y = center.y - radius;
		while (y <= center.y + radius)
		{
			if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
				ft_mlx_pixel_put(data->img, x, y, color);
			y++;
		}
		x++;
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
