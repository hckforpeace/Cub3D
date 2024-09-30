/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 14:46:04 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data data;
	(void)argv;

	if (argc == 2)
	{
		//data.fd_list = NULL;
		// if (!parser(argc, argv, &data))
		// 	return (1);
		if (!ft_mlx_init(&data))
			return (1);
		ft_events_init(&data);
		//close(data.fd);
	}
	return (0);
}
