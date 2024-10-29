/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:32:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/29 18:59:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_cursor(t_data *data)
{
	t_point center;
	t_point x_line;
	t_point	y_line;
	int		i;

	center.x = WIDTH / 2;
	center.y = HEIGHT / 2;
	ft_draw_circle(center, 1, WHITE, data);
	x_line.x = WIDTH / 2 - 4;
	x_line.y = HEIGHT / 2 - 10;
	i = x_line.x;
	while (i <= x_line.x + 8)
	{
		ft_mlx_pixel_put(data->img, i, x_line.y, WHITE);
		i++;
	}
	x_line.x = WIDTH / 2 - 4;
	x_line.y = HEIGHT / 2 + 10;
	i = x_line.x;
	while (i <= x_line.x + 8)
	{
		ft_mlx_pixel_put(data->img, i, x_line.y, WHITE);
		i++;
	}
	y_line.x = WIDTH / 2 - 10;
	y_line.y = HEIGHT / 2 - 4;
	i = y_line.y;
	while (i <= y_line.y + 8)
	{
		ft_mlx_pixel_put(data->img, y_line.x, i, WHITE);
		i++;
	}
	y_line.x = WIDTH / 2 + 10;
	y_line.y = HEIGHT / 2 - 4;
	i = y_line.y;
	while (i <= y_line.y + 8)
	{
		ft_mlx_pixel_put(data->img, y_line.x, i, WHITE);
		i++;
	}
}

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
	if (data->file->sprite_count > 0)
		ft_animate_sprite(data);
	if (data->door[data->file->door_count - 1].status == IS_OPENING)
		ft_animate_open_door(data);
	if (data->door[data->file->door_count - 1].status == IS_CLOSING)
		ft_animate_close_door(data);
	if (data->p->jump)
		ft_animate_jump(data);
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
		&data->img->line_len, &data->img->endian);
	ft_update_motion(data, data->p);
	//ft_draw_background(data);
	ft_floor_ceiling_raycast(data->floorcast, data->p, data);
	ft_raycast(data->ray, data->p, data);
	ft_minimap(data);
	ft_draw_cursor(data);
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
	while (y <= HEIGHT / 2 - data->p->pitch)
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
