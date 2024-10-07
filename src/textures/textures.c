/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:21:26 by pierre            #+#    #+#             */
/*   Updated: 2024/10/07 16:02:41 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures(t_data *data)
{
	data->textures[NORTH].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[NORTH].width), &(data->textures[NORTH].height));
	data->textures[NORTH].addr = mlx_get_data_addr(data->textures[NORTH].img, &data->textures[NORTH].bpp, &data->textures[NORTH].line_len, &data->textures[NORTH].endian);

	data->textures[EAST].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[EAST].width), &(data->textures[EAST].height));
	data->textures[EAST].addr = mlx_get_data_addr(data->textures[EAST].img, &data->textures[EAST].bpp, &data->textures[EAST].line_len, &data->textures[EAST].endian);

	data->textures[SOUTH].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[SOUTH].width), &(data->textures[SOUTH].height));
	data->textures[SOUTH].addr = mlx_get_data_addr(data->textures[SOUTH].img, &data->textures[SOUTH].bpp, &data->textures[SOUTH].line_len, &data->textures[SOUTH].endian);

	data->textures[WEST].img = mlx_xpm_file_to_image(data->mlx, data->file->EA, &(data->textures[WEST].width), &(data->textures[WEST].height));
	data->textures[WEST].addr = mlx_get_data_addr(data->textures[WEST].img, &data->textures[WEST].bpp, &data->textures[WEST].line_len, &data->textures[WEST].endian);


}