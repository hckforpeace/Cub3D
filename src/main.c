/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/04 17:18:10 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_file *fdata;
	t_data *data;
	t_raycast *ray;

	fdata = init_fdata();
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
	data->file = fdata;
	parser(argc, argv, fdata);
	if (ft_mlx_init(data))
		return (1);
	if (ft_player_init(data))
		return (1);
	ft_events_init(data);
	ft_render_map(data);	
	mlx_loop(data->mlx->mlx_con);
	parser_exit(fdata, "all good", 0);
	return (0);
}
