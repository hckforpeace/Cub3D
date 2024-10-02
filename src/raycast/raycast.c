/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:34:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/02 18:43:58 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	ft_init_rays(t_raycast *ray, t_player *p, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)WIDTH - 1;
	ray->dir.x = p->dir.x + p->plane.x * cam_x;
	ray->dir.y = p->dir.y + p->plane.y * cam_x;
	ray->map.x = (int)p->pos.x;
	ray->map.y = (int)p->pos.y;
	if (ray->dir.x != 0)
		ray->delta.x = fabs(1 / ray->dir.x);
	if (ray->dir.y != 0)
		ray->delta.y = fabs(1 / ray->dir.y);
}

static void	ft_step(t_raycast *ray, t_player *p)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side.x = (p->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side.x = (ray->map.x + 1.0 - p->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side.y = (p->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side.y = (ray->map.y + 1.0 - p->pos.y) * ray->delta.y;
	}
}

static	void	ft_dda(t_raycast *ray, t_data *data)
{
	while (1)
	{
		if (ray->side.x < ray->side.y)
		{
			ray->side.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side_col = 0;
		}
		else
		{
			ray->side.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side_col = 1;
		}
		if (data->map[(int)ray->map.y][(int)ray->map.x] == '1')
			break ;
	}
}

static void	ft_calculate_wall(t_raycast *ray, t_player *p)
{
	double	wall_dist;
	int		line_height;
	
	if (ray->side_col == 0)
		wall_dist = (ray->map.x - p->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
	else
		wall_dist = (ray->map.y - p->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
	line_height = (int)(HEIGHT / wall_dist);
	ray->y_start = -line_height / 2 + HEIGHT / 2;
	if (ray->y_start < 0)
		ray->y_start = 0;
	ray->y_end = line_height / 2 + HEIGHT / 2;
	if (ray->y_end >= HEIGHT)
		ray->y_end = HEIGHT - 1;
}

void	ft_raycast(t_raycast *ray, t_player *p, t_data *data)
{
	int	x;
		
	x = 0;
	while (x < WIDTH)
	{
		ft_init_rays(ray, p, x);
		ft_step(ray, p);
		ft_dda(ray, data);
		ft_calculate_wall(ray, p);
		if (ray->side_col == 0)
			ft_draw_vertical(x, ray->y_start, ray->y_end, RED1, data);
		else
			ft_draw_vertical(x, ray->y_start, ray->y_end, RED2, data);		
		printf("p->pos.x : %f, p->pos.y : %f\n", p->pos.x, p->pos.y);
		x++;
	}
}
//wall dist for textures
// if (side == 0)
// 	wall_x = pos_y + wall_dist * ray->delta.y;
// else
// 	wall_x = pos_x + wall_dist * ray->delta.x;
// wall_x -= floor(wall_x);
