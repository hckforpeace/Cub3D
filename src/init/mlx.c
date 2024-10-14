/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:47:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/10 16:55:16 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_init(t_data *data)
{
	t_img	*img;

	img = data->img;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (printf(MLX_CON), 1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (printf(MLX_WIN), 1);
	}
	// img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// if (!img->img)
	// {
	// 	mlx_destroy_window(data->mlx, data->mlx_win);
	// 	mlx_destroy_display(data->mlx);
	// 	free(data->mlx);
	// 	return (printf(MLX_IMG), 1);
	// }
	// img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
	// 	&img->endian);
	return (0);
}

void	ft_events(t_data *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, ft_key, data);
	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask, ft_mouse_tk, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, ft_close, data);
}
