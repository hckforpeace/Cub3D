/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:55:44 by pierre            #+#    #+#             */
/*   Updated: 2024/10/10 16:07:49 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_animation	*init_animation(int width, int height, int delay)
{
	t_animation *a;

	a = (struct s_animation*)malloc(sizeof(struct s_animation));
	if (!a)
		return (NULL);
	a->height = height;
	a->width = width;
	a->delay = delay;
	a->current_frame_num = 0;
	a->frame_count = 0;
	a->current_frame_num = 0;
	a->last_updated = 0;
	a->_tmp_delay = 0;
	a->frames = NULL;
	return (a);
}

t_animation		*slice_sprite(t_game *game, int frames, int delay) 
{
	int			i;
	t_animation	*a;
	t_slice		*slice;

	slice = game->sprites->slice;
	a = init_animation(slice->width, slice->height, delay);
	if (!a)
		return NULL;
	i = 0;
	while (i < frames)
	{
		add_frame(a, slice, game);
		slice->x += slice->width;
		if (slice->x >= slice->width)
		{
			slice->x = 0;
			slice->y += slice->height;
		}
		i++;
	}
	return (a);
}
