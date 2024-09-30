/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:27 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_data *data)
{
	t_mlx	*mlx;

	mlx = data->mlx;
	mlx_destroy_image(mlx->mlx_con, mlx->img);
	mlx_destroy_window(mlx->mlx_con, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_con);
	free(mlx->mlx_con);
	free(data->mlx);
	free(data);
	exit(0);
}
