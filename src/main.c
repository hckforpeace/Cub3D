/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 20:09:58 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update_animaton(void * ptr) {
	t_animation *a;
	t_img		*img;
	t_game 		*game;


	game = (t_game *)ptr;
	a = (t_animation *)game->sprites->animations->content;
	if (!a)
		return (0);
	if (a->_tmp_delay++ == a->delay)
	{
		printf("in\n");
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(a->frames);
		img = (t_img *)ft_lstget(a->frames, a->current_frame_num)->content;
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 150, 150);
	}
	// else
	// 	// printf("out\n");
	return (0);
}

// need the mlx init 
int	main(int argc, char **argv)
{
	t_file	*fdata;
	t_game	*game;
	t_slice	slice;

	slice.x = 0;
	slice.y = 0;
	slice.width = 32;
	slice.height = 32;
	game = (struct s_game *)malloc(sizeof(struct s_game));
	game->sprites = (struct s_sprite *)malloc(sizeof(struct s_sprite));
	game->sprites->animations = NULL;

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Hello world!");

	load_sprite(game, "sprite/fox.xpm", game->mlx);
	ft_lstadd_back_b(&game->sprites->animations, ft_lstnew_b(slice_sprite(game, &slice, 5, 10000), 0));

	mlx_loop_hook(game->mlx, update_animaton, game);
	// void* img = (t_img *)ft_lstget(a->frames, a->current_frame_num)->content;
	// mlx_put_image_to_window(game->mlx, game->mlx_win, (((t_animation *)game->sprites->animations->content)->frames->content->), 0, 0);
	mlx_loop(game->mlx);

	return (1);
}




/* #include "utils.h"
#include "sprite.h"
#include "libft.h"

int	update(t_list * list) {
	if (!list)
		return 1;
	ft_lstiter(list, update_animaiton);
	return 0;
}

int main(void)
{
 	t_win	tutorial;
	
	tutorial = new_window(600, 500, "animations");
	if (!tutorial.win_ptr)
		return (2);
	{
		/* Sprites 
		t_sprite s1 = new_sprite("link", "assets/link.xpm", &tutorial);
		if (!s1.sprite_img.img_ptr) {
			destroy_sprite(s1);
			destroy_window(tutorial);
			return (1);
		}
		sprite_slice slice1 = (sprite_slice){0, 0, 64, 64};
		ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite(s1, slice1, 7, 600, PLAYER)));
		printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width, s1.height, ft_lstsize(s1.animations));
		mlx_loop_hook(tutorial.mlx_ptr, update, s1.animations);
	}
	mlx_loop(tutorial.mlx_ptr);
	destroy_window(tutorial);
	return (0);
} */