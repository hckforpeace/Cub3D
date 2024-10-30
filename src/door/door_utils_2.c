/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:24:17 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/30 23:39:05 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_select_door(t_data *data, int y, int x, int i)
{
	if (((int)data->elem[i].pos.x == x) && ((int)data->elem[i].pos.y == y))
		return (1);
	return (0);
}

long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1);
	return ((unsigned long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

// long	t_start;

// 	t_start = ft_get_time();
// 	if (ft_get_time() - t_start < 1000)
// 		data->p->welcome = 1;
// 	else
// 		data->p->welcome = 0;

void	ft_print_welcome_message(t_data *data)
{
	if (data->p->welcome)
		mlx_string_put(data->mlx, data->mlx_win, WIDTH / 4, 5 * HEIGHT / 6, \
			WHITE, WELCOME_MSG);
}

void	ft_print_door_message(t_data *data)
{
	int	i;

	i = ft_find_nearest_door_index(data);
	if (i == -1)
		return ;
	if (data->elem[i].status == CLOSE && ft_is_near_door(data, i))
		mlx_string_put(data->mlx, data->mlx_win, WIDTH / 2, 4 * HEIGHT / 5, \
			WHITE, "Press 'E' to open the door !");
	if (data->elem[i].status == OPEN && ft_is_near_door(data, i))
		mlx_string_put(data->mlx, data->mlx_win, WIDTH / 2, 4 * HEIGHT / 5, \
			WHITE, "Press 'Q' to close the door !");
}
