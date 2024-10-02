/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 18:20:23 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_map_init(t_data *data)
{
	data->map = malloc(sizeof(char *) * 10);
	data->map[0] = "111111111";
	data->map[1] = "100010001";
	data->map[2] = "111000111";
	data->map[3] = "100000001";
	data->map[4] = "111000111";
	data->map[5] = "100000001";
	data->map[6] = "111000111";
	data->map[7] = "100000001";
	data->map[8] = "100000001";
	data->map[9] = "111111111";
	data->map[10] = "\0";
}

int main(int argc, char **argv)
{
	t_data *data;
	t_raycast *ray;

	(void)argv;
	if (argc != 2)
		return (printf(INPUT_ERROR), 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (-1);
	data->ray = ray;
	data->fd_list = NULL;
	if (!parser(argc, argv, data))
		return (1);
	if (ft_mlx_init(data))
		return (1);
	if (ft_player_init(data))
		return (1);
	ft_events_init(data);
	ft_map_init(data);
	ft_render_map(data);		
	close(data->fd);
	mlx_loop(data->mlx->mlx_con);
	return (0);
}
