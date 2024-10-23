/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:17 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 17:09:42 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_xpm_to_sprite(t_data *data, t_texture *tex, char *path, int id)
{
	t_img	*img;
	int		sprite_size;

	sprite_size = SPRITE_SIZE;
	img = mlx_xpm_file_to_image(data->mlx, path, &sprite_size, &sprite_size);
	if (!img)
		return ((void)printf("sprite texture not found"));
	tex->img[id].img = img;
	tex->img[id].addr = mlx_get_data_addr(img, &tex->img[id].bpp, \
		&tex->img[id].line_len, &tex->img[id].endian);
	if (!tex->img[id].addr)
		return ((void)printf("door mlx_get_data_addr failed"));
}

void	ft_xpm_to_img(t_data *data, t_texture *tex, char *path, int id)
{
	void	*img;
	int		tex_size;

	tex_size = TEX_SIZE;
	img =  mlx_xpm_file_to_image(data->mlx, path, &tex_size, &tex_size);
	if (!img)
		return ((void)printf("texture not found"));
	tex->img[id].img = img;
	tex->img[id].addr = mlx_get_data_addr(img, &tex->img[id].bpp, \
		&tex->img[id].line_len, &tex->img[id].endian);
	if (!tex->img[id].addr)
		return ((void)printf("texture mlx_get_data_addr failed"));
}

void	ft_textures_init(t_data *data)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
		return ;
	ft_bzero(tex, sizeof(tex));
	data->tex = tex;
	tex->img = ft_calloc(sizeof(int *), 14);
	if (!tex->img)
		return ;
	ft_xpm_to_img(data, data->tex, data->file->NO, NORTH);
	ft_xpm_to_img(data, data->tex, data->file->EA, EAST);
	ft_xpm_to_img(data, data->tex, data->file->SO, SOUTH);
	ft_xpm_to_img(data, data->tex, data->file->WE, WEST);
	ft_xpm_to_sprite(data, data->tex, "./sprites/0.xpm", SPRITE_0);
	ft_xpm_to_sprite(data, data->tex, "./sprites/1.xpm", SPRITE_1);
	ft_xpm_to_sprite(data, data->tex, "./sprites/2.xpm", SPRITE_2);
	ft_xpm_to_sprite(data, data->tex, "./sprites/3.xpm", SPRITE_3);
	ft_xpm_to_sprite(data, data->tex, "./sprites/4.xpm", SPRITE_4);
	ft_xpm_to_sprite(data, data->tex, "./sprites/5.xpm", SPRITE_5);
	ft_xpm_to_sprite(data, data->tex, "./sprites/6.xpm", SPRITE_6);
	ft_xpm_to_sprite(data, data->tex, "./sprites/7.xpm", SPRITE_7);
	ft_xpm_to_sprite(data, data->tex, "./sprites/8.xpm", SPRITE_8);
	ft_xpm_to_sprite(data, data->tex, "./sprites/9.xpm", SPRITE_9);
}
