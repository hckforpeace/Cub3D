/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:57:19 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 13:30:23 by pierre           ###   ########.fr       */
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

void	load_sprites(void *mlx, t_file *file)
{
	char	*tab[13] = {"./sprite/jump1.xpm", "./sprite/jump2.xpm", "./sprite/jump3.xpm", "./sprite/jump4.xpm", "./sprite/jump5.xpm", "./sprite/jump6.xpm", "./sprite/jump7.xpm", "./sprite/jump8.xpm", "./sprite/jump9.xpm", "./sprite/jump10.xpm", "./sprite/jump11.xpm", "./sprite/jump12.xpm", 0};
	int		i;

	i = 0;
	while (tab[i])
	{
		fprintf(stderr, "loaded\n\n");
		file->sprites[i].img = mlx_xpm_file_to_image(mlx, "./sprite/jump1.xpm", &file->sprites[i].width, &file->sprites[i].height);
		if (!file->sprites[i].img)
			fprintf(stderr, "wrong file\n");
		file->sprites[i].addr = mlx_get_data_addr(file->sprites[i].img, &file->sprites[i].bits_per_pixel, &file->sprites[i].line_length, &file->sprites[i].endian);
		i++;
	}
}

// need the mlx init 
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	t_file	*data;

	data = init_fdata();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// load_sprites(mlx, data);
	
	data->sprites[0].img = mlx_xpm_file_to_image(mlx, "./sprite/jump1.xpm", &data->sprites[0].width, &data->sprites[0].height);
	if (!data->sprites[0].img)
		fprintf(stderr, "wrong file\n");
	data->sprites[0].addr = mlx_get_data_addr(data->sprites[0].img, &data->sprites[0].bits_per_pixel, &data->sprites[0].line_length, &data->sprites[0].endian);
	mlx_put_image_to_window(mlx, mlx_win, &data->sprites[0].img,0,0);
	fprintf(stderr, "hello world\n");
	mlx_loop(mlx);


	return (1);
}


