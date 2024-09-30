/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 14:39:31 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define INPUT_ERROR "wrong input:\n\n expected ./cub3d file_name.cub\n"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# define MLX_CON "\n\nError while initilaizing the mlx\n"
# define MLX_WIN "\n\nError while creating\n"
# define MLX_IMG "\n\nError while creating the image\n"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_mlx
{
	void	*mlx_con;
	void	*mlx_win;
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_data
{
	t_list	*fd_list;
	t_mlx	*mlx;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		fd;
} t_data;

// added by Pablo

/*Mlx init*/
int		ft_mlx_init(t_data *data);
void	ft_events_init(t_data *data);

/*Events handlers*/
int	ft_close(t_data *data);

// added by Pierre

// ./src/parser
int	parser(int argc, char **argv, t_data *data);

// ./src/display
void	display(t_list *lst);

#endif
