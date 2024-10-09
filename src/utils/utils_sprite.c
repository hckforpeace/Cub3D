/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:39:53 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 16:44:33 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	mlx_get_pixel_color(t_img *img, int x, int y)
{
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int *)(img->addr + (y * img->line_length + x
			* (img->bits_per_pixel >> 3))));
}
