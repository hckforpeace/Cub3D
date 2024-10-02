/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:22 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/02 15:55:21 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (keysym == XK_w && data->map[(int)(data->p->pos.x - 0.4)][(int)(data->p->pos.y)] != '1')
		data->p->pos.x -= 0.1;
	else if (keysym == XK_s && data->map[(int)(data->p->pos.x + 0.4)][(int)(data->p->pos.y)] != '1')
		data->p->pos.x += 0.1;
	else if (keysym == XK_d && data->map[(int)(data->p->pos.x)][(int)(data->p->pos.y + 0.4)] != '1')
		data->p->pos.y += 0.1;
	else if (keysym == XK_a && data->map[(int)(data->p->pos.x)][(int)(data->p->pos.y - 0.4)] != '1')
		data->p->pos.y -= 0.1;
	// else if (keysym == XK_Right)
	// {

	// }
	// else if (keysym == XK_Left)
	// {

	// }
	//ft_render_map(data);
	return (0);
}

int ft_close(t_data *data)
{
	t_mlx *mlx;

	mlx = data->mlx;
	mlx_destroy_image(mlx->mlx_con, mlx->img);
	mlx_destroy_window(mlx->mlx_con, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_con);
	free(mlx->mlx_con);
	free(data->mlx);
	free(data);
	exit(0);
}
