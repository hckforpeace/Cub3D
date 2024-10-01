/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 12:29:07 by pbeyloun         ###   ########.fr       */
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
	data.map = NULL;
	data.start[0] = -1.0;
	data.start[1] = -1.0;
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
