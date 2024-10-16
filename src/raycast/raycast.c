/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:34:57 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/16 15:59:25 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (data->file->map[(int)ray->map.y][(int)ray->map.x] == '1')
			break ;
	}
}

static void	ft_calculate_wall(t_raycast *ray, t_player *p)
{
	double	wall_dist;

	if (ray->side_col == 0)
		wall_dist = (ray->map.x - p->pos.x + (1 - ray->step.x) / 2) \
			/ ray->dir.x;
	else
		wall_dist = (ray->map.y - p->pos.y + (1 - ray->step.y) / 2) \
			/ ray->dir.y;
	ray->height = (int)(HEIGHT / wall_dist);
	ray->y_vertical.x = -ray->height / 2 + HEIGHT / 2;
	if (ray->y_vertical.x < 0)
		ray->y_vertical.x = 0;
	ray->y_vertical.y = ray->height / 2 + HEIGHT / 2;
	if (ray->y_vertical.y >= HEIGHT)
		ray->y_vertical.y = HEIGHT - 1;
	if (ray->side_col == 0)
		ray->wall_x = p->pos.y + wall_dist * ray->dir.y;
	else
		ray->wall_x = p->pos.x + wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	ft_get_texture_orientation(t_texture *tex, t_raycast *ray)
{
	if (ray->side_col == 0)
	{
		if (ray->dir.x < 0)
			tex->orientation = WEST;
		else
			tex->orientation = EAST;
	}
	else
	{
		if (ray->dir.y > 0)
			tex->orientation = SOUTH;
		else
			tex->orientation = NORTH;
	}
}

// void	ft_init_texture_pixels(t_data *data)
// {
// 	int	i;

// 	if (data->pixels)
// 		ft_free_tab(data->pixels);
// 	data->pixels = ft_calloc(sizeof(int *), HEIGHT + 1);
// 	if (!data->pixels)
// 		return ;
// 	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		data->pixels[i] = ft_calloc(sizeof(int), WIDTH + 1);
// 		if (!data->pixels[i])
// 			return ;
// 		i++;
// 	}
// }

void	ft_calculate_text(t_data *data, t_texture *tex, t_raycast *ray, int x)
{
	int			y;
	int			color;

	ft_get_texture_orientation(tex, ray);
	tex->x = (int)(ray->wall_x * TEX_SIZE);
	if ((ray->side_col == 0 && ray->dir.x < 0) \
		|| (ray->side_col == 1 && ray->dir.y > 0))
		tex->x = TEX_SIZE - tex->x - 1;
	tex->step = 1.0 * TEX_SIZE / ray->height;
	tex->pos = (ray->y_vertical.x - HEIGHT / 2 + ray->height / 2) * tex->step;
	y = ray->y_vertical.x;
	while (y < ray->y_vertical.y)
	{
		tex->y = (int)tex->pos & (TEX_SIZE - 1);
		tex->pos += tex->step;
		color = data->textures[tex->orientation][TEX_SIZE * tex->y + tex->x];
		if (tex->orientation == NORTH || tex->orientation == SOUTH)
			color = (color >> 1) & 8355711;
		if (color > 0)
			ft_mlx_pixel_put(data->img, x, y, color);
		y++;
	}
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
		ft_calculate_text(data, data->tex, data->ray, x);
		x++;
	}
}
