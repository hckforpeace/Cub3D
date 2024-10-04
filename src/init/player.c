/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/04 22:44:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_player_init(t_data *data)
{
	t_player	*p;
	
	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		return (-1);
	data->p = p;
	p->pos.x = data->file->start[1];
	p->pos.y = data->file->start[0];
	// printf("\n\n\n\ny pos : %f\n", data->file->start[0]);
	p->ceiling_col = ft_rgb_to_hex(data->file->crgb);
	p->floor_col = ft_rgb_to_hex(data->file->frgb);
	// printf("pos_x : %f, pos_y : %f\n", p->pos.x, p->pos.y);
	p->angle = 0.05;
	p->direction = data->file->orientation;
	if (p->direction == 'N')
	{
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = 0.66;
		p->plane.y = 0;
	}
	if (p->direction == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
		p->plane.x = -0.66;
		p->plane.y = 0;
	}
	if (p->direction == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
	if (p->direction == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = -0.66;
	}
	return (0);
}
