/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:23:40 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/15 18:31:40 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_aux_x(t_point *start, t_point *end, t_point *p, t_point *p_inc)
{
	int temp;
	
	if (start->x > end->x)
	{
		temp = start->x;
		start->x = end->x;
		end->x = temp;
		temp = start->y;
		start->y = end->y;
		end->y = temp;
	}
	p_inc->y = -1;
	if (end->y >= start->y)
		p_inc->y = 1;
	p->y = start->y;
	p->x = start->x;
}

void ft_bresenham(t_point start, t_point end, t_data *data)
{
	t_point delta;
	t_point p;
	t_point p_inc;
	int d;

	delta.x = fabs(end.x - start.x);
	delta.y = fabs(end.y - start.y);
	if (delta.x > delta.y)
	{
		ft_aux_x(&start, &end, &p, &p_inc);
		d = 2 * delta.y - delta.x;
		while (p.x <= end.x)
		{
			if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
				ft_mlx_pixel_put(data->img, p.x, p.y, RED);
			if (d > 0)
			{
				p.y += p_inc.y;
				d -= 2 * delta.x;
			}
			d += 2 * delta.y;
			p.x++;
		}
	}
	else
	{

		while (p.y <= end.y)
		{
			if (p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT)
				ft_mlx_pixel_put(data->img, p.x, p.y, RED);
			if (d > 0)
			{
				p.x += p_inc.x;
				d -= 2 * delta.y;
			}
			d += 2 * delta.x;
			p.y++;
		}
	}
}
