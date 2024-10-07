/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:21:26 by pierre            #+#    #+#             */
/*   Updated: 2024/10/07 15:09:28 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_data *data)
{
	data->textures[0].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[0].width), &(data->textures[0].height));
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bpp, &data->textures[0].line_len, &data->textures[0].endian);

	data->textures[1].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[1].width), &(data->textures[1].height));
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].img, &data->textures[1].bpp, &data->textures[1].line_len, &data->textures[1].endian);

	data->textures[2].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[2].width), &(data->textures[2].height));
	data->textures[2].addr = mlx_get_data_addr(data->textures[2].img, &data->textures[2].bpp, &data->textures[2].line_len, &data->textures[2].endian);

	data->textures[3].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[3].width), &(data->textures[3].height));
	data->textures[3].addr = mlx_get_data_addr(data->textures[3].img, &data->textures[3].bpp, &data->textures[3].line_len, &data->textures[3].endian);


}