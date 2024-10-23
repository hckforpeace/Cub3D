/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:10:23 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 12:58:22 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_minimap(t_data *data)
{
	t_minimap	*minimap;

	minimap = (t_minimap *)malloc(sizeof(t_minimap));
	if (!minimap)
		return ;
	data->minimap = minimap;
	minimap->size = ft_min(WIDTH, HEIGHT) / 6;
	minimap->start.x = WIDTH / 50;
	minimap->start.y = 9 * HEIGHT / 12;
}

void	ft_draw_tile(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (x + j > data->minimap->start.x && x + j < data->minimap->start.x + data->minimap->size && y + i > data->minimap->start.y && y + i < data->minimap->start.y + data->minimap->size)
				ft_mlx_pixel_put(data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_minimap *minimap, t_data *data)
{
	t_point	center;
	t_point	player_dir;
	int		radius;

	center.x = minimap->start.x + minimap->size / 2;
	center.y = minimap->start.y + minimap->size / 2;
	radius = TILE_SIZE / 2;
	ft_draw_circle(center, radius, RED, data);
	player_dir.x = center.x + 3 * TILE_SIZE * data->p->dir.x / 2;
	player_dir.y = center.y + 3 * TILE_SIZE * data->p->dir.y / 2;
	ft_bresenham(center, player_dir, data);
}

void	ft_draw_border(t_minimap *minimap, t_data *data)
{
	int	x;
	int	y;

	y = minimap->start.y - 5;
	while (y < minimap->start.y + minimap->size + 5)
	{
		x = minimap->start.x - 5;
		while (x < minimap->start.x + minimap->size + 5)
		{
			if (y < minimap->start.y || y > minimap->start.y + minimap->size || x < minimap->start.x || x > minimap->start.x + minimap->size)
				ft_mlx_pixel_put(data->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}

int	ft_count_column(char *map)
{
	return (ft_strlen(map));
}

int	ft_count_row(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_start_y(t_minimap *minimap, t_data *data)
{
	(void)minimap;
	return (minimap->start.y + minimap->size / 2 - data->p->pos.y * TILE_SIZE + 2);
}

int	ft_start_x(t_minimap *minimap, t_data *data)
{
	(void)minimap;
	return (minimap->start.x + minimap->size / 2 - data->p->pos.x * TILE_SIZE + 2);
}

void	ft_draw_blur_minimap(t_minimap *minimap, t_data* data)
{
	t_point	p;

	p.y = minimap->start.y;
	while (p.y < minimap->start.y + minimap->size)
	{
		p.x = minimap->start.x;
		while (p.x < minimap->start.x + minimap->size)
		{
			if (p.y > minimap->start.y && p.y < minimap->start.y + minimap->size && p.x > minimap->start.x && p.x < minimap->start.x + minimap->size)
				ft_put_pixel_blurred(data->img, &p, WHITE);
			p.x++;
		}
		p.y++;
	}
}

void	ft_draw_minimap(t_minimap *minimap, t_data *data)
{
	int	x;
	int	y;
	int	y_row;
	int	x_column;

	y = ft_start_y(minimap, data);
	y_row = 0;
	while (y_row < ft_count_row(data->file->map))
	{
		x_column = 0;
		x = ft_start_x(minimap, data);
		while (x_column < ft_count_column(data->file->map[y_row]))
		{
			if (data->file->map[y_row][x_column] == '1')
				ft_draw_tile(data, x, y, BLACK);
			if (data->file->map[y_row][x_column] == 'X')
				ft_draw_tile(data, x, y, LAVANDE);
			x += TILE_SIZE;
			x_column++;
		}
		y += TILE_SIZE;
		y_row++;
	}
}

void	ft_minimap(t_data *data)
{
	ft_init_minimap(data);
	ft_draw_blur_minimap(data->minimap, data);
	ft_draw_minimap(data->minimap, data);
	ft_draw_border(data->minimap, data);
	ft_draw_player(data->minimap, data);
}
