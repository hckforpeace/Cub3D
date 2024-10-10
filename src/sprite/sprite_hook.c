/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:19:10 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/10 15:24:05 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int update_animaton(void * ptr)
{
	t_animation *a;
	t_img		*img;
	t_game 		*game;
	t_point		center;

	center.x = 960; 
	center.y = 540; 
	game = (t_game *)ptr;
	a = (t_animation *)game->sprites->animations->content;
	if (!a)
		return (0);
	if (a->_tmp_delay++ == a->delay)
	{
		a->_tmp_delay = 0;
		a->current_frame_num++;
		a->current_frame_num %= ft_lstsize(a->frames);
		img = (t_img *)ft_lstget(a->frames, a->current_frame_num)->content;
		draw_sprite(10, img, &game->fimg, &center);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->fimg.img, 0, 0);
	}
	return (0);
}
