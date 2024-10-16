/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/16 22:37:26 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_collision(double x, double y, t_data *data)
{
	if (data->file->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

unsigned int ft_get_pixel_color(t_img *img, int x, int y)
{
    char *color;

    color = img->addr + (y * img->line_len + x * (img->bpp / 8));
    return (*(unsigned int *)color);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
