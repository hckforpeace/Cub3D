/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:01:51 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/01 14:10:40 by pbeyloun         ###   ########.fr       */
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
