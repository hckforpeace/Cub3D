/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 15:17:39 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define INPUT_ERROR "wrong input:\n\n expected ./cub3d file_name.cub\n"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# define MLX_CON "\n\nError while initilaizing the mlx\n"
# define MLX_WIN "\n\nError while creating\n"
# define MLX_IMG "\n\nError while creating the image\n"

# define WIDTH 1000
# define HEIGHT 1000

/*Colors*/
# define WHITE 0xFFFFFFF
# define BLACK 0x0000000

typedef struct s_pt
{
	double x;
	double y;
}	t_pt;

typedef struct s_player
{
	struct s_pt	pos;
	struct s_pt	dir;
	struct s_pt	plane;
}	t_player;


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
	t_list		*fd_list;
	t_mlx		*mlx;
	t_player	*p;
	char		**map;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			fd;
} t_data;

// added by Pablo

/*Mlx init*/
int		ft_mlx_init(t_mlx *mlx);
void	ft_events_init(t_data *data);

/*Player*/
void	ft_player_init(t_player *p);

/*Events handlers*/
int	ft_close(t_data *data);

/*Raycast*/
void	ft_bresenham(t_pt p0, t_pt p1, t_data *data);
void	ft_raycast(t_data *data, t_player *p);

// added by Pierre

// ./src/parser
int	parser(int argc, char **argv, t_data *data);

// ./src/display
void	display(t_list *lst);

#endif
