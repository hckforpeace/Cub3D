/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:35:43 by pierre            #+#    #+#             */
/*   Updated: 2024/10/16 12:50:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_door(int x, int y, char **map)
{
	if (!is_valid_zero(x, y, map))
		return (0);
	else if (map[x - 1][y] == '1' && map[x + 1][y] == '1')
		return (1);
	else if (map[x][y - 1] == '1' && map[x][y + 1] == '1')
		return (1);
	else
		return (0);
}
