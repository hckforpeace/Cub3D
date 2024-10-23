/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:46 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 15:34:39 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_animate_sprite(t_data *data)
{
	static int fps = 0;

	if (fps < 60)
		data->tex->tex_id = SPRITE_0;
	else if (fps < 70)
		data->tex->tex_id = SPRITE_1;
	else if (fps < 80)
		data->tex->tex_id = SPRITE_2;
	else if (fps < 90)
		data->tex->tex_id = SPRITE_3;
	else if (fps < 100)
		data->tex->tex_id = SPRITE_4;
	else if (fps < 110)
		data->tex->tex_id = SPRITE_5;
	else if (fps < 120)
		data->tex->tex_id = SPRITE_6;
	else if (fps < 130)
		data->tex->tex_id = SPRITE_7;
	else if (fps < 140)
		data->tex->tex_id = SPRITE_8;
	else if (fps < 200)
		data->tex->tex_id = SPRITE_9;
	else if (fps < 210)
		data->tex->tex_id = SPRITE_8;
	else if (fps < 220)
		data->tex->tex_id = SPRITE_7;
	else if (fps < 230)
		data->tex->tex_id = SPRITE_6;
	else if (fps < 240)
		data->tex->tex_id = SPRITE_5;
	else if (fps < 250)
		data->tex->tex_id = SPRITE_4;
	else if (fps < 260)
		data->tex->tex_id = SPRITE_3;
	else if (fps < 270)
		data->tex->tex_id = SPRITE_2;
	else if (fps < 280)
		data->tex->tex_id = SPRITE_1;
	else
		fps = 0;
	fps++;
}
