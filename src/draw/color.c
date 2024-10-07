/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:16:35 by pajimene          #+#    #+#             */
/*   Updated: 2024/10/07 12:01:41 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rgb_to_hex(int *rgb)
{
	if (rgb[0] < 0)
		rgb[0] = 0;
	if (rgb[0] > 255)
		rgb[0] = 255;
	if (rgb[1] < 0)
		rgb[1] = 0;
	if (rgb[1] > 255)
		rgb[1] = 255;
	if (rgb[2] < 0)
		rgb[2] = 0;
	if (rgb[2] > 255)
		rgb[2] = 255;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
