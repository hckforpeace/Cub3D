/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:05 by pierre            #+#    #+#             */
/*   Updated: 2024/09/29 19:36:32 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_list *lst)
{
	if (!lst)
		fprintf(stderr, "no content in the file\n");
	while (lst)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}
