/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:17 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/16 15:58:36 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_xpm_to_img(t_data *data, char *path)
{
	t_img	*img;
	int		text_size;
	int		*buffer;
	int		x;
	int		y;

	img = malloc(sizeof(t_img));
	text_size = TEX_SIZE;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &text_size, &text_size);
	if (!img->img)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, \
		&img->endian);
	if (!img->addr)
		return (NULL);
	buffer = ft_calloc(1, sizeof(int) * TEX_SIZE * TEX_SIZE);
	if (!buffer)
		return (NULL);
	y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			buffer[y * TEX_SIZE + x] = *(int *)(img->addr + \
				(y * img->line_len + x * (img->bpp / 8)));
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
	free(img);
	return (buffer);
}

void	ft_textures_init(t_data *data)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		return ;
	ft_bzero(tex, sizeof(tex));
	data->tex = tex;
	data->textures = ft_calloc(sizeof(int *), 5);
	if (!data->textures)
		return ;
	data->textures[NORTH] = ft_xpm_to_img(data, data->file->NO);
	data->textures[EAST] = ft_xpm_to_img(data, data->file->EA);
	data->textures[SOUTH] = ft_xpm_to_img(data, data->file->SO);
	data->textures[WEST] = ft_xpm_to_img(data, data->file->WE);
}
