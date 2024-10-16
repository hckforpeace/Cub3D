/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:16:35 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/16 23:24:52 by pajimene         ###   ########.fr       */
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
	return((rgb >> 16) & 0xFF);
}

int	ft_get_g(int rgb)
{
	return((rgb >> 8) & 0xFF);
}

int	ft_get_b(int rgb)
{
	return(rgb & 0xFF);
}

unsigned int ft_blur(t_img *img, int x, int y, int blur_radius)
{
    t_rgb	total;
	t_rgb	avg;
    unsigned int	color;
	int count;
	int	i;
	int	j;
	int	n_x;
	int	n_y;
	
	total.r = 0;
	total.g = 0;
	total.b = 0;	
	count = 0;
	i = -blur_radius;
    while (i <= blur_radius)
	{
        j = -blur_radius;
		while (j <= blur_radius)
		{
            n_x = x + i;
            n_y = y + j;
            if (n_x >= 0 && n_x < WIDTH && n_y >= 0 && n_y < HEIGHT)
			{
                color = ft_get_pixel_color(img, n_x, n_y);
                total.r += ft_get_r(color);
                total.g += ft_get_g(color);
                total.b += ft_get_b(color);
                count++;
            }
			j++;
        }
		i++;
    }
	avg.r = total.r / count;
    avg.g = total.g / count;
    avg.b = total.b / count;
	avg.rgb[0] = avg.r;
	avg.rgb[1] = avg.g;
	avg.rgb[2] = avg.b;
    return (ft_rgb_to_hex(avg.rgb));
}

void ft_put_pixel_blurred(t_img *img, t_point *p, int blur_radius, unsigned int color, float alpha)
{
    unsigned int bg_color;
	t_rgb	front;
	t_rgb	back;
	t_rgb	blur;
	
	bg_color = ft_blur(img, p->x, p->y, blur_radius);
    front.r = ft_get_r(color);
    front.g = ft_get_g(color);
    front.b = ft_get_b(color);
    back.r = ft_get_r(bg_color);
    back.g = ft_get_g(bg_color);
    back.b = ft_get_b(bg_color);
    blur.r = (int)((1 - alpha) * back.r + alpha * front.r);
    blur.g = (int)((1 - alpha) * back.g + alpha * front.g);
    blur.b = (int)((1 - alpha) * back.b + alpha * front.b);
	blur.rgb[0] = blur.r;
	blur.rgb[1] = blur.r;
	blur.rgb[2] = blur.b;
    char *color_def = img->addr + ((int)p->y * img->line_len + (int)p->x * (img->bpp / 8));
    *(unsigned int *)color_def = ft_rgb_to_hex(blur.rgb);
}
