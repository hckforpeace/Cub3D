/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:10:23 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/15 18:15:36 by pajimene         ###   ########.fr       */
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
	minimap->tile_size = minimap->size / 9;
	minimap->start.x = minimap->size / 4;
	minimap->start.y = HEIGHT - 5 * minimap->size / 4 - minimap->tile_size;
	minimap->data = data;
}

void	ft_draw_minimap_tile(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			ft_mlx_pixel_put(minimap->data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

char	*ft_minimap_column(int y, t_minimap *minimap, t_data *data)
{
	char	*column;
	t_point	p_pos;
	int		x;

	(void)minimap;
	p_pos = data->p->pos;
	column = malloc(sizeof(char *) * 9);
	x = 0;
	while (x < 9)
	{
		if ((int)p_pos.y - 4 + y > 0 && (int)p_pos.y - 4 + y < 37)
		{
			if (data->file->map[(int)p_pos.y - 4 + y][(int)p_pos.x - 4 + x] == '1')
				column[x] = '1';
			if (data->file->map[(int)p_pos.y - 4 + y][(int)p_pos.x - 4 + x] == '0')
				column[x] = '0';
		}
		x++;
	}
	return (column);
}

void	ft_parse_minimap(t_minimap *minimap, t_data *data)
{
	int	y;

	minimap->map = ft_calloc(sizeof(char *), 10);
	if (!minimap->map)
		return ;
	y = 0;
	while (y < 9)
	{
		minimap->map[y] = ft_minimap_column(y, minimap, data);
		// if (!minimap->map[y])
		// 	ft_free_tab(minimap->map);
		y++;
	}
}

void	ft_render_minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (minimap->map[(int)(y / minimap->tile_size)][(int)(x / minimap->tile_size)] == '1')
				ft_draw_minimap_tile(minimap, x + minimap->start.x, y + minimap->start.y, BLACK);
			else
				ft_draw_minimap_tile(minimap, x + minimap->start.x, y + minimap->start.y, GREY);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_minimap *minimap, t_data *data)
{
	t_point	center;
	t_point	player_dir;
	int		radius;

	center.x = minimap->start.x + minimap->size / 2;
	center.y = minimap->start.y + minimap->size / 2;
	radius = minimap->size / 25;
	ft_draw_circle(center, radius, RED, data);
	player_dir.x = center.x + 20 * data->p->dir.x;
	player_dir.y = center.y + 20 * data->p->dir.y;
	ft_bresenham(center, player_dir, data);
}
void	ft_draw_border(t_minimap *minimap, t_data *data)
{
	int	x;
	int	y;

	y = minimap->start.y - 5;
	while (y < minimap->start.y + minimap->size + 20)
	{
		x = minimap->start.x - 5;
		while (x < minimap->start.x + minimap->size + 20)
		{
			if (y < minimap->start.y || y > minimap->start.y + minimap->size + 15 || x < minimap->start.x || x > minimap->start.x + minimap->size + 15)
				ft_mlx_pixel_put(data->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	ft_minimap(t_data *data)
{
	t_minimap *minimap;

	ft_init_minimap(data);
	minimap = data->minimap;
	ft_parse_minimap(minimap, data);
	ft_render_minimap(minimap);
	ft_draw_border(minimap, data);
	ft_draw_player(minimap, data);
	free(minimap->map);
}
