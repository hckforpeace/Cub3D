/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:48:47 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 15:39:32 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_lst(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp)
	{
		lst = temp;
		temp = lst->next;
		free(lst->content);
		free(lst);
	}
}

void	parser_exit(t_file *fdata, char *exmessage, int exno)
{
	if (fdata->fd_list)
		free_lst(fdata->fd_list);
	if (fdata->map)
		clear_wordar(fdata->map);
	if (fdata->NO)
		free(fdata->NO);
	if (fdata->SO)
		free(fdata->SO);
	if (fdata->WE)
		free(fdata->WE);
	if (fdata->EA)
		free(fdata->EA);
	printf("%s\n", exmessage);
	exit(exno);
}
