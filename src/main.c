/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/04 21:43:30 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_get_pixel_color(t_data *img, int x, int y)
{
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int *)(img->addr + (y * img->line_length + x
			* (img->bits_per_pixel >> 3))));
}

void 	my_display(t_data *img)
{
	int	x;
	int	y;
	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			printf("x: %d, y: %d, color: %d\n", x, y, mlx_get_pixel_color(img, x, y));
			y++;
		}
		x++;
	}
}

// need the mlx init 
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	t_file	*data;
	char 	*text1 = "./wall.xpm";
	char 	*text2 = "./wall2.xpm";
	
	mlx = mlx_init();
	data = init_fdata();


	data->textures[0].img = mlx_xpm_file_to_image(mlx, text1, &(data->textures[0].width), &(data->textures[0].height));
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bits_per_pixel, &data->textures[0].line_length, &data->textures[0].endian);
	
	data->textures[1].img = mlx_xpm_file_to_image(mlx, text2, &(data->textures[1].width), &(data->textures[1].height));
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].img, &data->textures[1].bits_per_pixel, &data->textures[1].line_length, &data->textures[1].endian);
	
	
	my_display(&data->textures[1]);	
	my_display(&data->textures[0]);
	
	// parser(argc, argv, data);
	// parser_exit(data, "all good", 0);
	return (0);
}
