/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/16 19:43:14 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_file	*fdata;
	t_data	*data;

	fdata = init_fdata();
	data = ft_init_data();
	if (argc != 2)
		return (printf(INPUT_ERROR), 1);
	data->file = fdata;
	parser(argc, argv, fdata);
	if (ft_mlx_init(data))
		return (1);
	ft_textures_init(data);
	if (ft_player_init(data))
		return (1);
	ft_render_map(data);
	ft_events(data);
	mlx_loop_hook(data->mlx, ft_render_map, data);
	mlx_loop(data->mlx);
	parser_exit(fdata, "all good", 0);
	return (0);
}
