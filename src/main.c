/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 16:08:55 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;
	t_mlx	*mlx;
	t_player	*p;

	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (argc == 2)
	{
		//data->fd_list = NULL;
		//if (!parser(argc, argv, data))
		///	return (1);
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		if (!mlx)
			return (-1);
		data->mlx = mlx;
		if (ft_mlx_init(data->mlx))
			return (1);
		ft_events_init(data);
		p = (t_player *)malloc(sizeof(t_player));
		if (!p)
			return (-1);
		data->p = p;
		ft_player_init(data->p);
		data->map = malloc(sizeof(char *) * 10);
		data->map[0] = "111111111";
		data->map[1] = "100010001";
		data->map[2] = "111000111";
		data->map[3] = "100000001";
		data->map[4] = "111000111";
		data->map[5] = "100000001";
		data->map[6] = "111000111";
		data->map[7] = "100010001";
		data->map[8] = "100010001";
		data->map[9] = "111111111";
		data->map[10] = "\0";
		ft_raycast(data, data->p);
		mlx_put_image_to_window(data->mlx->mlx_con, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
		//close(data->fd);
		mlx_loop(data->mlx->mlx_con);
	}
	return (0);
}
