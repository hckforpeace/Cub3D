/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:03:43 by pierre            #+#    #+#             */
/*   Updated: 2024/10/10 15:18:27 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	draw_sprite(float scale, t_img *sub, t_img *win, t_point *center)
{
	int	i;
	int color;
	int	j;
	int	x;
	int y;

	i = 0;
	while (i < sub->height * scale)
	{
		j = 0;
		while (j < sub->width * scale)
		{
			if (scale > 1)
			{
				x = i / scale;
				y = j / scale;
			}
			else
			{
				x = i * scale;
				y = j * scale;
			}
			color = mlx_get_pixel_color(sub, x, y);
			if  (color > 0)
				my_mlx_pixel_put(win, i, j, color);
			j++;
		}
		i++;
	}
} */


void	draw_sprite(float scale, t_img *sub, t_img *win, t_point *center)
{
	int	i;
	int color;
	int	j;
	int	x;
	int y;

	i = 0;
	while (i < sub->height * scale)
	{
		j = 0;
		while (j < sub->width * scale)
		{
			if (scale > 1)
			{
				x = i / scale;
				y = j / scale;
			}
			else
			{
				x = i * scale;
				y = j * scale;
			}
			color = mlx_get_pixel_color(sub, x, y);
			if  (color > 0)
			{
				my_mlx_pixel_put(win, (i + center->x) - ( (sub->height * scale) / 2), (j + center->y) - ((sub->width * scale) / 2),  color);
			}
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(win, 960, 540, 255);
}