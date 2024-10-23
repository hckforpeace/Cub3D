/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:16:35 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/21 12:25:51 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rgb_to_hex(int *rgb)
{
	if (rgb[0] < 0)
		rgb[0] = 0;
	if (rgb[0] > 255)
		rgb[0] = 255;
	if (rgb[1] < 0)
		rgb[1] = 0;
	if (rgb[1] > 255)
		rgb[1] = 255;
	if (rgb[2] < 0)
		rgb[2] = 0;
	if (rgb[2] > 255)
		rgb[2] = 255;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	ft_get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

int	ft_get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	ft_get_b(int rgb)
{
	return (rgb & 0xFF);
}

static void	ft_blur_radius(int *count, t_point *p, t_rgb *total, t_img *img)
{
	int				i;
	int				j;
	t_point			new;
	unsigned int	color;

	i = -5;
	while (i <= 5)
	{
		j = -5;
		while (j <= 5)
		{
			new.x = p->x + i;
			new.y = p->y + j;
			if (new.x >= 0 && new.x < WIDTH && new.y >= 0 && new.y < HEIGHT)
			{
				color = ft_get_pixel_color(img, new.x, new.y);
				total->r += ft_get_r(color);
				total->g += ft_get_g(color);
				total->b += ft_get_b(color);
				(*count)++;
			}
			j++;
		}
		i++;
	}
}

unsigned int	ft_blur(t_img *img, t_point *p)
{	
	t_rgb	total;
	t_rgb	avg;
	int		count;

	total.r = 0;
	total.g = 0;
	total.b = 0;
	count = 0;
	ft_blur_radius(&count, p, &total, img);
	avg.r = total.r / count;
	avg.g = total.g / count;
	avg.b = total.b / count;
	avg.rgb[0] = avg.r;
	avg.rgb[1] = avg.g;
	avg.rgb[2] = avg.b;
	return (ft_rgb_to_hex(avg.rgb));
}

void	ft_put_pixel_blurred(t_img *img, t_point *p, unsigned int color)
{
	unsigned int	bg_color;
	char			*color_def;
	t_rgb			front;
	t_rgb			back;
	t_rgb			blur;

	bg_color = ft_blur(img, p);
	front.r = ft_get_r(color);
	front.g = ft_get_g(color);
	front.b = ft_get_b(color);
	back.r = ft_get_r(bg_color);
	back.g = ft_get_g(bg_color);
	back.b = ft_get_b(bg_color);
	blur.r = (int)((1 - 0.1) * back.r + 0.1 * front.r);
	blur.g = (int)((1 - 0.1) * back.g + 0.1 * front.g);
	blur.b = (int)((1 - 0.1) * back.b + 0.1 * front.b);
	blur.rgb[0] = blur.r;
	blur.rgb[1] = blur.r;
	blur.rgb[2] = blur.b;
	color_def = img->addr + ((int)p->y * img->line_len + \
		(int)p->x * (img->bpp / 8));
	*(unsigned int *)color_def = ft_rgb_to_hex(blur.rgb);
}
