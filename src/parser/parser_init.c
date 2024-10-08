/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:33:41 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/08 21:26:28 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
