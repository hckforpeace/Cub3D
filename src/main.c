/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/07 15:11:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_init_data();
	data->file = init_fdata();
	if (argc != 2)
		return (printf(INPUT_ERROR), 1);
	parser(argc, argv, data->file);
	if (ft_mlx_init(data))
		return (1);
	textures(data);
	if (ft_player_init(data))
		return (1);
	ft_render_map(data);
	ft_events(data);
	mlx_loop_hook(data->mlx, ft_render_map, data);
	mlx_loop(data->mlx);
	// parser_exit(fdata, "all good", 0);
	return (0);
}
