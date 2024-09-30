/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/09/30 14:40:02 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_con, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx_con, data->mlx->mlx_win);
	mlx_destroy_display(data->mlx->mlx_con);
	free(data->mlx->mlx_con);
	exit(0);
}
