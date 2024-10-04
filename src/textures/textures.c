/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:53 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/04 17:25:11 by pbeyloun         ###   ########.fr       */
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

void	save_textures(t_file *file)
{
	void	*img;
	img = mlx_xpm_file_to_image(&file->textures[0], file->EA, &file->textures[0].width, &file->textures[0].height);
	file->textures[0].pixel = mlx_get_data_addr(&file->textures[0], &file->textures[0].bpp, &file->textures[0].line_len, &file->textures[0].line_len);
	// display_pixels(&file->textures[0]);
}