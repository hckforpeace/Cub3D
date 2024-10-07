/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:21:26 by pierre            #+#    #+#             */
/*   Updated: 2024/10/07 13:38:00 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_data *data)
{
	// data->mlx = 0;
	// printf("%s", data->file->EA);
	data->textures[0].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[0].width), &(data->textures[0].height));
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bpp, &data->textures[0].line_len, &data->textures[0].endian);
}