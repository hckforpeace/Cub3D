/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:48 by pierre            #+#    #+#             */
/*   Updated: 2024/10/10 16:26:03 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*init_sprite(char *name, char *path, void *mlx, t_slice *slice)
{
	t_sprite	*sprite;

	sprite = (struct s_sprite *)malloc(sizeof(struct s_sprite));
	if (!ft_strcmp(name, "fox"))
	sprite->slice = slice; 
	sprite->animations = NULL;
	sprite->file_path = path;
	sprite->name = name;
	sprite->z_index = 0;
	if (load_sprite(sprite, mlx))
		return (free(sprite), NULL); 
	return (sprite);
}

int	load_sprite(t_sprite *sprite, void *mlx)
{
	sprite->sprite_img.img = mlx_xpm_file_to_image(mlx, sprite->file_path, &(sprite->sprite_img.width), &(sprite->sprite_img.height));
	if (!sprite->sprite_img.img)
	{
		ft_putstr_fd("error when opening sprite path\n", 2);
		return (1);
	}
	sprite->sprite_img.addr = mlx_get_data_addr(sprite->sprite_img.img, &sprite->sprite_img.bits_per_pixel, &sprite->sprite_img.line_length, &sprite->sprite_img.endian);
	return (0);
}

int	add_frame(t_animation *a, t_slice *slice, t_game *game)
{
	int		i;
	int		j;
	t_img	*frame;

	frame = (struct s_img *)malloc(sizeof(struct s_img));
	if (!frame)
		return (1);
	frame->width = slice->width;
	frame->height = slice->height;
	frame->img = mlx_new_image(game->mlx, slice->width, slice->height);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel, &frame->line_length, &frame->endian);
	i = 0;
	while (i < slice->width)
	{
		j = 0;
		while (j < slice->height)
		{
			my_mlx_pixel_put(frame, i, j, mlx_get_pixel_color(&game->sprites->sprite_img, i + slice->x, j + slice->y));
			j++;
		}
		i++;
	}
	ft_lstadd_back_b(&a->frames, ft_lstnew_b(frame, 0));
	return (1);
}