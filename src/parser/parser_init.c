/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/22 17:22:00 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*ft_init_data(t_file *fdata)
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
	ray->z_buffer = ft_calloc(WIDTH + 1, sizeof(int));
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
	data->tex = NULL;
	data->img = img;
	data->ray = ray;
	data->p = p;
	data->spriteray = spriteray;
	data->fdata = fdata;
	return (data);
}

t_file	*init_fdata(void)
{
	t_file	*fdata;

	fdata = (struct s_file *)malloc(sizeof(struct s_file));
	if (!fdata)
		parser_exit(NULL, "failed malloc", 0);
	fdata->fd_list = NULL;
	fdata->EA = NULL;
	fdata->NO = NULL;
	fdata->SO = NULL;
	fdata->WE = NULL;
	fdata->map = NULL;
	fdata->start[0] = -1;
	fdata->start[1] = -1;
	fdata->crgb[0] = -1;
	fdata->crgb[1] = -1;
	fdata->crgb[2] = -1;
	fdata->frgb[0] = -1;
	fdata->frgb[1] = -1;
	fdata->frgb[2] = -1;
	fdata->sprite_count = 0;
	return (fdata);
}
