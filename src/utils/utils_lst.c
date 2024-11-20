/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:01:51 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/02 15:40:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	retreives the number of node that have a char * content
	that is not empty/white spaces/etc 
*/
int	get_lstlen(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list && !ft_isemptyline((char *)list->content))
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	end_of_map(t_list *list, int len)
{
	while (len > 0)
	{
		list = list->next;
		len--;
	}
	if (!list)
		return (1);
	while (list)
	{
		if (!ft_isemptyline((char *)list->content))
			return (0);
		list = list->next;
	}
	return (1);
}
