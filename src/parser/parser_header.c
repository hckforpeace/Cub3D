/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:22 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/02 15:24:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	saves in the structure the data texture then the color
	and returns NULL if it incounters any problem
*/
static t_list	*txture_color(t_file *fdata, t_list *list)
{
	list = save_texture(list, fdata);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (0);
	list = save_color(list, fdata);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	return (list);
}

/*
	saves in the structure the data color then the texture
	and returns NULL if it incounters any problem
*/
static t_list	*color_txture(t_file *fdata, t_list *list)
{
	list = save_color(list, fdata);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (0);
	list = save_texture(list, fdata);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	return (list);
}

/* 
	checks what is the first type of element found if it 
	does match texture or color it return NULL
*/
static t_list	*parse_texture_color(t_file *fdata, t_list *list)
{
	if (ft_istexture((char *)list->content))
		return (txture_color(fdata, list));
	else if (ft_iscolor((char *)list->content))
		return (color_txture(fdata, list));
	return (NULL);
}

int	no_duplicate(t_file *fdata)
{
	if (fdata->EA == NULL || fdata->WE == NULL || fdata->SO == NULL
		|| fdata->NO == NULL || fdata->crgb[0] == -1 || fdata->frgb[0] == -1)
		return (0);
	return (1);
}

//TODO add check that there is at least white 
// space after the first two blocks
t_list	*parse_header(t_file *fdata, t_list *list)
{
	if (!list)
		parser_exit(fdata, "Empty file !", 1);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		parser_exit(fdata, "Invalid format !", 1);
	list = parse_texture_color(fdata, list);
	if (!list || !no_duplicate(fdata))
		parser_exit(fdata, "Invalid format !", 1);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		parser_exit(fdata, "Missing map", 1);
	return (list);
}
