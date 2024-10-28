/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/28 22:34:57 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*ft_init_data(t_file *file)
{
	t_data		*data;
	t_raycast	*ray;
	t_img		*img;
	t_player	*p;
	t_spriteray	*spriteray;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		parser_exit(NULL, "failed malloc", 0);
	ray = (t_raycast *)malloc(sizeof(t_raycast));
	if (!ray)
		parser_exit(NULL, "failed malloc", 0);
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		parser_exit(NULL, "failed malloc", 0);
	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		parser_exit(NULL, "failed malloc", 0);
	spriteray = (t_spriteray *)malloc(sizeof(t_spriteray));
	if (!spriteray)
		parser_exit(NULL, "failed malloc", 0);
	ft_bzero(img, sizeof(img));
	ft_bzero(ray, sizeof(ray));
	ft_bzero(p, sizeof(p));
	ft_bzero(spriteray, sizeof(spriteray));
	data->img = img;
	data->ray = ray;
	data->p = p;
	data->spriteray = spriteray;
	data->file = file;
	return (data);
}

t_file	*init_file(void)
{
	t_file	*file;

	file = (struct s_file *)malloc(sizeof(struct s_file));
	if (!file)
		parser_exit(NULL, "failed malloc", 0);
	file->fd_list = NULL;
	file->EA = NULL;
	file->NO = NULL;
	file->SO = NULL;
	file->WE = NULL;
	file->map = NULL;
	file->start[0] = -1;
	file->start[1] = -1;
	file->crgb[0] = -1;
	file->crgb[1] = -1;
	file->crgb[2] = -1;
	file->frgb[0] = -1;
	file->frgb[1] = -1;
	file->frgb[2] = -1;
	file->sprite_count = 0;
	file->door_count = 0;
	return (file);
}
