/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:53 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/04 22:46:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_get_pixel_color(t_mlx *img, int x, int y)
{
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int *)(img->pixel + (y * img->line_len + x
			* (img->bpp >> 3))));
}

void	save_textures(t_file *fdata, t_data *data, void *mlx)
{
	fprintf(stderr, "ici\n");
	// data->textures[0].img = mlx_xpm_file_to_image(mlx, fdata->NO, &(data->textures[0].width), &(data->textures[0].height));
	// data->textures[0].pixel = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bpp, &data->textures[0].line_len, &data->textures[0].endian);
// 
	// data->textures[1].img = mlx_xpm_file_to_image(mlx, fdata->SO, &(data->textures[1].width), &(data->textures[1].height));
	// data->textures[1].pixel = mlx_get_data_addr(data->textures[1].img, &data->textures[1].bpp, &data->textures[1].line_len, &data->textures[0].endian);
// 
// 
	// data->textures[2].img = mlx_xpm_file_to_image(mlx, fdata->EA, &(data->textures[2].width), &(data->textures[2].height));
	// data->textures[2].pixel = mlx_get_data_addr(data->textures[2].img, &data->textures[2].bpp, &data->textures[2].line_len, &data->textures[0].endian);
// 
	// data->textures[3].img = mlx_xpm_file_to_image(mlx, fdata->WE, &(data->textures[3].width), &(data->textures[3].height));
	// data->textures[3].pixel = mlx_get_data_addr(data->textures[3].img, &data->textures[3].bpp, &data->textures[3].line_len, &data->textures[0].endian);
}