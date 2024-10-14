/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:17 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/14 20:03:14 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*ft_xpm_to_img(t_data *data, char *path)
{
	t_img	temp;
	int		*buffer;
	int		x;
	int		y;

	temp.img = mlx_xpm_file_to_image(data->mlx, path, &data->tex->size, &data->tex->size);
	if (!temp.img)
		return (NULL);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bpp, &temp.line_len, &temp.endian);
	buffer = ft_calloc(1, sizeof(int) * data->tex->size * data->tex->size);
	if (!buffer)
		return (NULL);
	y = 0;
	while (y < data->tex->size)
	{
		x = 0;
		while (x < data->tex->size)
		{
			buffer[y * data->tex->size + x] = (int)temp.addr[y * data->tex->size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, temp.img);
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
	data->tex->size = TEX_SIZE;
	data->textures = ft_calloc(sizeof(int *), 5);
	if (!data->textures)
		return ;
	data->textures[NORTH] = ft_xpm_to_img(data, data->file->NO);
	data->textures[EAST] = ft_xpm_to_img(data, data->file->EA);
	data->textures[SOUTH] = ft_xpm_to_img(data, data->file->SO);
	data->textures[WEST] = ft_xpm_to_img(data, data->file->WE);
}
