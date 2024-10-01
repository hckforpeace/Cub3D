/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:34:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/01 16:11:49 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	ft_raycast(t_data *data, t_player *p)
{
	//init rays
	int	x;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;

	//precalculate dda
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;

	int		step_x;
	int		step_y;	
	
	x = 0;
	while (x < WIDTH)
	{
		cam_x = 2 * x / (double)WIDTH - 1;
		ray_dir_x = p->dir.x + p->plane.x * cam_x;
		ray_dir_y = p->dir.y + p->plane.y * cam_x;

		map_x = (int)p->pos.x;
		map_y = (int)p->pos.y;
		if (ray_dir_x != 0)
			delta_x = fabs(1 / ray_dir_x);
		else
			delta_x = 10000000000000;
		if (ray_dir_y != 0)
			delta_y = fabs(1 / ray_dir_y);
		else
			delta_y = 10000000000000;
		
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_x = (p->pos.x - map_x) * delta_x;
		}
		else
		{
			step_x = 1;
			side_x = (map_x + 1.0 - p->pos.x) * delta_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_y = (p->pos.y - map_y) * delta_y;
		}
		else
		{
			step_y = 1;
			side_y = (map_y + 1.0 - p->pos.y) * delta_y;
		}
		int	side;
		while (1)
		{
			if (side_x < side_y)
			{
				side_x += delta_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_y += delta_y;
				map_y += step_y;
				side = 1;
			}
			//printf("map_x=%d, map_y=%d\n", (int)p->pos.x, (int)p->pos.y);
			if (data->map[map_x][map_y] == '1')
				break ;
		}
		double	wall_dist;
		if (side == 0)
			wall_dist = (map_x - p->pos.x + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - p->pos.y + (1 - step_y) / 2) / ray_dir_y;
		// if (side == 0)
		// 	wall_dist = (map_x - p->pos.x + (1 - step_x) / 2) / ray_dir_x;
		// else
		// 	wall_dist = (map_y - p->pos.y + (1 - step_y) / 2) / ray_dir_y;

		//printf("Ray Dir: (%f, %f), Map: (%d, %d), WallDist: %f\n", ray_dir_x, ray_dir_y, map_x, map_y, wall_dist);
		int line_height = (int)(HEIGHT / wall_dist);
		printf("x : %d, line_height : %d\n", x, line_height);
		int draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;

		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		
		//printf("x=%f, start->%d, end->%d\n", x, draw_start, draw_end);
		// if (side == 0)
		// 	wall_x = pos_y + wall_dist * ray->dy;
		// else
		// 	wall_x = pos_x + wall_dist * ray->dx;
		// wall_x -= floor(wall_x);
		x++;
	}
}
