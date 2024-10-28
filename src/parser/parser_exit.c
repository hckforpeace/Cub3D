/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:48:47 by pierre            #+#    #+#             */
/*   Updated: 2024/10/28 20:21:09 by pajimene         ###   ########.fr       */
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

void	parser_exit(t_file *file, char *exmessage, int exno)
{
	if (file->fd_list)
		free_lst(file->fd_list);
	if (file->map)
		clear_wordar(file->map);
	if (file->NO)
		free(file->NO);
	if (file->SO)
		free(file->SO);
	if (file->WE)
		free(file->WE);
	if (file->EA)
		free(file->EA);
	free(file);
	printf("%s\n", exmessage);
	exit(exno);
}
