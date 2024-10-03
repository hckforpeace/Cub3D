/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/03 16:57:41 by pajimene         ###   ########.fr       */
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
	p->pos.x = 4;
	p->pos.y = 4;
	p->angle = 0.05;
	//p->jump = 0.0;
	p->direction = 'E';
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
