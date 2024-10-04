/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/04 17:53:39 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void ft_map_init(t_data *data)
// {
// 	data->map = malloc(sizeof(char *) * 10);
// 	data->map[0] = "11111111111111";
// 	data->map[1] = "10001000000001";
// 	data->map[2] = "11100011000001";
// 	data->map[3] = "10000000100001";
// 	data->map[4] = "11100011100001";
// 	data->map[5] = "10000000110001";
// 	data->map[6] = "11100011100001";
// 	data->map[7] = "10000000000001";
// 	data->map[8] = "10000000110001";
// 	data->map[9] = "11111111111111";
// 	data->map[10] = "\0";
// }

int main(int argc, char **argv)
{
 	t_file *fdata;
	t_data *data;
	t_raycast *ray;

	fdata = init_fdata();
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (-1);
	data->ray = ray;
	data->file = fdata;
	parser(argc, argv, fdata);
	if (ft_mlx_init(data))
		return (1);
	if (ft_player_init(data))
		return (1);
	ft_events_init(data);
	ft_render_map(data);		
	mlx_loop(data->mlx->mlx_con);
	// parser_exit(fdata, "all good", 0);
	return (0);
}
