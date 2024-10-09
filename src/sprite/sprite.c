/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:48 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 20:09:07 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	load_sprite(t_game *game, char *path_to_srpite, void *mlx)
{
	game->sprites->sprite_img.img = mlx_xpm_file_to_image(mlx, path_to_srpite, &(game->sprites->sprite_img.width), &(game->sprites->sprite_img.height));
	if (!game->sprites->sprite_img.img)
	{
		fprintf(stderr, "error when opening xpm file\n");
		exit(1);
	}
	game->sprites->sprite_img.addr = mlx_get_data_addr(game->sprites->sprite_img.img, &game->sprites->sprite_img.bits_per_pixel, &game->sprites->sprite_img.line_length, &game->sprites->sprite_img.endian);
	// printf("x: %d, y: %d, color: %d \n", 0, 0, mlx_get_pixel_color(&game->sprites->sprite_img,0,0));
	// my_display(game->sprites());
	
}

void	add_frame(t_animation *a, t_slice *slice, t_game *game)
{
	int		i;
	int		j;
	t_img	*frame;

	frame = (struct s_img *)malloc(sizeof(struct s_img));
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
}