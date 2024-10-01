/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:22 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/01 14:02:34 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	saves in the structure the data texture then the color
	and returns NULL if it incounters any problem
*/
static t_list	*txture_color(t_data *data, t_list* list)
{
	list = save_texture(list, data);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (/* empty file*/0);
	list = save_color(list, data);
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
static t_list	*color_txture(t_data *data, t_list* list)
{
	list = save_color(list, data);
	if (!list)
		return (0);
	if (!ft_isemptyline((char *)list->content))
		return (NULL);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (/* empty file*/0);
	list = save_texture(list, data);
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
static t_list	*parse_texture_color(t_data *data, t_list* list)
{
	if (ft_istexture((char *)list->content))
		return (txture_color(data, list));
	else if (ft_iscolor((char *)list->content))
		return (color_txture(data, list));
	return (NULL); 
}

//TODO add check that there is at least white 
// space after the first two blocks
t_list	*parse_header(t_data *data, t_list *list)
{
	if (!list)
		return (/* empty file */0);
	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (/* empty file*/0);
	list = parse_texture_color(data, list);
	if (!list)
		return (0);
 	while (list && ft_isemptyline((char *)list->content))
		list = list->next;
	if (!list)
		return (/* empty file*/0);
/* 	while (list)
	{
		printf("%s", (char *)list->content);
		list = list->next;
	} */
	return (list);
}
