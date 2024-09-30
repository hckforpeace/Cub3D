/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:05 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 00:15:37 by pierre           ###   ########.fr       */
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

void	display_data(t_data *data)
{
	if (data->EA)
		printf("EA: %s\n", data->EA);
	if (data->NO)
		printf("NO: %s\n", data->NO);
	if (data->SO)
		printf("SO: %s\n", data->SO);
	if (data->WE)
		printf("WE: %s\n", data->WE);
	printf("Frgp: %d,%d,%d\n", data->frgb[0], data->frgb[1], data->frgb[2]);
	printf("Crgp: %d,%d,%d\n", data->crgb[0], data->crgb[1], data->crgb[2]);
}
