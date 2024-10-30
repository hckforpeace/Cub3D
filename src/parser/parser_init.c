/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/30 18:17:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*ft_init_data(void)
{
	t_data		*data;
	t_raycast	*ray;
	t_floorcast	*floorcast;
	t_img		*img;
	t_player	*p;
	t_spriteray	*spriteray;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_free_all(data, "Malloc failed", 1);
	data->file = init_file(data);
	ray = (t_raycast *)malloc(sizeof(t_raycast));
	if (!ray)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(ray, sizeof(ray));
	data->ray = ray;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(img, sizeof(img));
	data->img = img;
	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(p, sizeof(p));
	data->p = p;
	spriteray = (t_spriteray *)malloc(sizeof(t_spriteray));
	if (!spriteray)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(spriteray, sizeof(spriteray));
	data->spriteray = spriteray;
	floorcast = (t_floorcast *)malloc(sizeof(t_floorcast));
	if (!floorcast)
		ft_free_all(data, "Malloc failed", 1);
	ft_bzero(floorcast, sizeof(floorcast));
	data->floorcast = floorcast;
	return (data);
}

t_file	*init_file(t_data *data)
{
	t_file	*file;

	file = (struct s_file *)malloc(sizeof(struct s_file));
	if (!file)
		ft_free_all(data, "Malloc failed", 1);
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
	file->elem_count = 0;
	return (file);
}
