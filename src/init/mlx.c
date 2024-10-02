/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:47:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/02 12:34:23 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_init(t_data *data)
{
	t_mlx	*mlx;
	
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (-1);
	data->mlx = mlx;
	mlx->mlx_con = mlx_init();
	if (!mlx->mlx_con)
		return (printf(MLX_CON), 1);
	mlx->mlx_win = mlx_new_window(mlx->mlx_con, WIDTH, HEIGHT, "cub3d");
	if (!mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_con);
		free(mlx->mlx_con);
		return (printf(MLX_WIN), 1);
	}
	mlx->img = mlx_new_image(mlx->mlx_con, WIDTH, HEIGHT);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx_con, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_con);
		free(mlx->mlx_con);
		return (printf(MLX_IMG), 1);
	}
	mlx->pixel = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, \
		&mlx->endian);
	return (0);
}

void	ft_events_init(t_data *data)
{
	mlx_hook(data->mlx->mlx_win, KeyPress, KeyPressMask, ft_key, data);
	//mlx_hook(mlx->mlx_win, ButtonPress, ButtonPressMask, ft_mouse, raycast);
	//mlx_hook(mlx->mlx_win, MotionNotify, PointerMotionMask, track, raycast);
	mlx_hook(data->mlx->mlx_win, DestroyNotify, StructureNotifyMask, ft_close, data);
}
