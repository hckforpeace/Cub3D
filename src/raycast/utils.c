/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/07 12:17:48 by pajimene         ###   ########.fr       */
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

// void	ft_bresenham(t_point p0, t_point p1, t_data *data)
// {
// 	t_point	d;
// 	t_point	s;
// 	double	gradient_err_1;
// 	double	gradient_err_2;

// 	d.x = fabs(p1.x - p0.x);
// 	if (p0.x < p1.x)
// 		s.x = 1;
// 	if (p0.x > p1.x)
// 		s.x = -1;
// 	d.y = fabs(p1.y - p0.y);
// 	if (p0.y < p1.y)
// 		s.y = 1;
// 	if (p0.y > p1.y)
// 		s.y = -1;
// 	if (d.x > d.y)
// 		gradient_err_1 = d.x / 2;
// 	if (d.x < d.y)
// 		gradient_err_1 = -d.y / 2;
// 	while (1)
// 	{
// 		ft_mlx_pixel_put(data->img, p0.x, p0.y, WHITE);
// 		if (p0.x == p1.x && p0.y == p1.y)
// 			break ;
// 		gradient_err_2 = gradient_err_1;
// 		if (gradient_err_2 > -d.x)
// 		{
// 			gradient_err_1 -= d.y;
// 			p0.x += s.x;
// 		}
// 		if (gradient_err_2 < d.y)
// 		{
// 			gradient_err_1 += d.x;
// 			p0.y += s.y;
// 		}
// 	}
// }
