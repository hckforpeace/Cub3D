/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 22:43:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;
	
	data.fd_list = NULL;
	data.EA = NULL;
	data.NO = NULL;
	data.SO = NULL;
	data.WE = NULL;
	data.crgb[0] = -1;
	data.crgb[1] = -1;
	data.crgb[2] = -1;

	data.frgb[0] = -1;
	data.frgb[1] = -1;
	data.frgb[2] = -1;
	
	if (!parser(argc, argv, &data))
		return (1);
	close(data.fd);
	return (0);
}
