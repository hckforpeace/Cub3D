/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/07 13:17:29 by pierre           ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	data->mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");


	data->main_img.img =  mlx_new_image(mlx, 1920, 1080);
	data->main_img.addr =  mlx_get_data_addr(data->main_img.img, &data->main_img.bits_per_pixel, &data->main_img.line_length,
								&data->main_img.endian);


	data->textures[0].img = mlx_xpm_file_to_image(mlx, text1, &(data->textures[0].width), &(data->textures[0].height));
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].img, &data->textures[0].bits_per_pixel, &data->textures[0].line_length, &data->textures[0].endian);
	
	data->textures[1].img = mlx_xpm_file_to_image(mlx, text2, &(data->textures[1].width), &(data->textures[1].height));
	data->textures[1].addr = mlx_get_data_addr(data->textures[1].img, &data->textures[1].bits_per_pixel, &data->textures[1].line_length, &data->textures[1].endian);
	
	
	my_mlx_pixel_put(&data->main_img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, data->mlx_win, data->main_img.img, 0, 0);
	my_display(&data->textures[1]);	
	my_display(&data->textures[0]);
	mlx_loop(mlx);
	
	// parser(argc, argv, data);
	// parser_exit(data, "all good", 0);
	return (0);
}


