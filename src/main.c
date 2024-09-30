/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 15:21:43 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;
	t_mlx	*mlx;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (argc == 2)
	{
		data->fd_list = NULL;
		if (!parser(argc, argv, data))
			return (1);
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		if (!mlx)
			return (-1);
		data->mlx = mlx;
		if (ft_mlx_init(data->mlx))
			return (1);
		ft_events_init(data);
		close(data->fd);
		mlx_loop(data->mlx->mlx_con);
	}
	return (0);
}
