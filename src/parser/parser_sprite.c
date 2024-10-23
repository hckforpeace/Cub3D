/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:27 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/23 18:08:59 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_count_sprites(t_file *fdata)
{
	int	i;
	int	j;

	i = 0;
	while (fdata->map[i])
	{
		j = 0;
		while (fdata->map[i][j])
		{
			if (fdata->map[i][j] == 'X')
				fdata->sprite_count++;
			j++;
		}
		i++;
	}
	fdata->sprite = ft_calloc(fdata->sprite_count, sizeof(t_sprite));
	if (!fdata->sprite)
		return ;
}

void	ft_parse_sprites(t_file *fdata)
{
	int	i;
	int	j;
	int	x;

	ft_count_sprites(fdata);
	i = 0;
	x = 0;
	while (fdata->map[i])
	{
		j = 0;
		while (fdata->map[i][j])
		{
			if (fdata->map[i][j] == 'X')
			{
				fdata->sprite[x].pos.x = j + 0.5;
				fdata->sprite[x].pos.y = i + 0.5;
				x++;
			}
			j++;
		}
		i++;
	}
}
