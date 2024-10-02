/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 15:45:27 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_file	data;

	data.fd_list = NULL;
	data.EA = NULL;
	data.NO = NULL;
	data.SO = NULL;
	data.WE = NULL;
	data.map = NULL;
	data.start[0] = -1.0;
	data.start[1] = -1.0;
	data.crgb[0] = -1;
	data.crgb[1] = -1;
	data.crgb[2] = -1;
	data.frgb[0] = -1;
	data.frgb[1] = -1;
	data.frgb[2] = -1;
	parser(argc, argv, &data);
	parser_exit(&data, "all good", 0);
	return (0);
}
