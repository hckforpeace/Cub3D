/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/07 11:59:59 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*ft_init_data(void)
{
	t_data		*data;
	t_raycast	*ray;
	t_img		*img;
	t_player	*p;

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
	ft_bzero(img, 5);
	ft_bzero(ray, 7);
	ft_bzero(p, 9);
	data->img = img;
	data->ray = ray;
	data->p = p;
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
	return (fdata);
}
