/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:26:10 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 17:11:09 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_apply_sprite_texture(t_data *data, int id, int x, int y)
{
	int	color;

	color = ft_get_pixel_color(&data->tex->img[id], data->spriteray->tex.x, \
		data->spriteray->tex.y);
	if ((color & 0x00FFFFFF) != 0)
		ft_mlx_pixel_put(data->img, x, y, color);
}

void	ft_transform_sprite(t_data *data, int index)
{
	t_spriteray	*spr;
	t_player	*p;

	spr = data->spriteray;
	p = data->p;
	spr->ray.x = data->fdata->sprite[index].pos.x - p->pos.x;
	spr->ray.y = data->fdata->sprite[index].pos.y - p->pos.y;
	spr->inv_det = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	spr->trans.x = spr->inv_det * \
		(p->dir.y * spr->ray.x - p->dir.x * spr->ray.y);
	spr->trans.y = spr->inv_det * \
		(-p->plane.y * spr->ray.x + p->plane.x * spr->ray.y);
	spr->screen_x = (int)((WIDTH / 2) * (1 + spr->trans.x / spr->trans.y));
}

void	ft_calc_width_height(t_data *data)
{
	t_spriteray	*spr;

	spr = data->spriteray;
	spr->sprite_height = fabs((HEIGHT / (spr->trans.y)));
	spr->draw_start.y = -spr->sprite_height / 2 + HEIGHT / 2;
	if (spr->draw_start.y < 0)
		spr->draw_start.y = 0;
	spr->draw_end.y = spr->sprite_height / 2 + HEIGHT / 2;
	if (spr->draw_end.y >= HEIGHT)
		spr->draw_end.y = HEIGHT - 1;
	spr->sprite_width = fabs((HEIGHT / (spr->trans.y)));
	spr->draw_start.x = -spr->sprite_width / 2 + spr->screen_x;
	if (spr->draw_start.x < 0)
		spr->draw_start.x = 0;
	spr->draw_end.x = spr->sprite_width / 2 + spr->screen_x;
	if (spr->draw_end.x >= WIDTH)
		spr->draw_end.x = WIDTH - 1;
}

void	ft_draw_sprites(t_data *data)
{
	t_spriteray	*spr;
	int			x;
	int			d;
	int			y;

	spr = data->spriteray;
	x = spr->draw_start.x - 1;
	while (++x < spr->draw_end.x)
	{
		y = spr->draw_start.y - 1;
		spr->tex.x = (int)(256 * (x - (-spr->sprite_width / 2 + \
			spr->screen_x)) * SPRITE_SIZE / spr->sprite_width) / 256;
		if (spr->trans.y > 0 && x > 0 && x < WIDTH && \
			spr->trans.y < data->ray->z_buffer[x])
		{
			while (++y < spr->draw_end.y)
			{
				d = y * 256 - HEIGHT * 128 + spr->sprite_height * 128;
				spr->tex.y = ((d * SPRITE_SIZE) / spr->sprite_height) / 256;
				ft_apply_sprite_texture(data, data->tex->tex_id, x, y);
			}
		}
	}
}
