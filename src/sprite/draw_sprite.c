/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:03:43 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 22:31:40 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(float scale, t_img *sub, t_img *win)
{
	int	new_width;
	int	new_height;
	int	i;
	int	j;
	int	x;
	int y;
	printf("scale : %f\n", scale);

	new_width = (sub->width * scale);
	new_height = (sub->height * scale);

	i = 0;
	// printf("drawing: %d, %d, the color : %d\n", i, j,  mlx_get_pixel_color(sub, x, y));
	printf("new_height: %d \n", sub->width);
	while (i < new_height)
	{
		j = 0;
		while (j < new_height)
		{
			if (scale > 1)
			{
				x = i / scale;
				// printf("%d\n", x);
				y = j / scale;
			}
			else
			{
				x = i * scale;
				// printf("%d\n", x);
				y = j * scale;
			}
			my_mlx_pixel_put(win, i, j, mlx_get_pixel_color(sub, x, y));
			j++;
		}
		i++;
	}
}