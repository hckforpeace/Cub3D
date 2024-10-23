/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:47:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/21 15:41:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_init(t_data *data)
{
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
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (printf(MLX_IMG), 1);
	}
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
		&data->img->line_len, &data->img->endian);
	return (0);
}
