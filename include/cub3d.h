/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/04 17:48:05 by pajimene         ###   ########.fr       */
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
# define INVALID_MAPCONTENT "Invalid characters in MAP !\n\t the map can containt only white spaces, 0, 1, and only one  (N, S, E, W)"
# define INVALID_MAPSHAPE "Invalid map !\n\t The player must be surrounded by walls"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# define MLX_CON "\n\nError while initilaizing the mlx\n"
# define MLX_WIN "\n\nError while creating\n"
# define MLX_IMG "\n\nError while creating the image\n"

/*Window dimensions*/
# define WIDTH 1000
# define HEIGHT 900

/*Colors*/
# define WHITE 0xFFFFFFF
# define BLACK 0x0000000
# define PINK 0xFFB3BA
# define YELLOW 0xFFDFBA
# define GREEN 0xBAE1FF
# define LAVANDE 0xD5BAFF
# define MENTHE 0xBAFFC9
# define RED1 0xFFCCCC
# define RED2 0xFF7F7F

typedef struct s_point
{
	double x;
	double y;
}	t_point;

typedef struct s_raycast
{
	struct s_point	dir;
	struct s_point	map;
	struct s_point	side;
	struct s_point	delta;
	struct s_point	step;
	int				y_start;
	int				y_end;
	int				side_col;
}	t_raycast;

typedef struct s_player
{
	char		direction;
	struct s_point	pos;
	struct s_point	dir;
	struct s_point	plane;
	struct s_point	mouse;
	int				hide_mouse;
	double			angle;
	int				ceiling_col;
	int				floor_col;
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

typedef struct s_file
{
	t_list	*fd_list;
	char	**map;
	int		crgb[3];
	int		frgb[3];
	char	orientation;
	double	start[2];
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		fd;
}	t_file;

typedef struct s_data
{
	t_file		*file;
	t_mlx		*mlx;
	t_player	*p;
	t_raycast	*ray;
}	t_data;

// added by Pablo

t_file	*init_fdata();

/*Mlx*/
int		ft_mlx_init(t_data *data);
void	ft_events_init(t_data *data);
void	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

/*Player*/
int		ft_player_init(t_data *data);

/*Events handlers*/
int		ft_close(t_data *data);
int		ft_key(int keysym, t_data *data);
int		ft_mouse_track(int x, int y, t_data *data);
int		ft_wall_collision(double x, double y, t_data *data);

/*Raycast*/
void	ft_bresenham(t_point p0, t_point p1, t_data *data);
void	ft_raycast(t_raycast *ray, t_player *p, t_data *data);

/*Draw*/
void	ft_draw_background(t_data *data);
void	ft_draw_vertical(int x, int y_start, int y_end, int color, t_data *data);
int		ft_render_map(t_data *data);
int		ft_rgb_to_hex(int *rgb);

// added by Pierre

// ./src/parser/parser.c
void	parser_exit(t_file *fdata, char *exmessage, int exno);

// ./src/parser/parser.c
void	parser(int argc, char **argv, t_file *fdata);
t_list	*parse_header(t_file *data, t_list *list);

// ./src/parser/parse_save.c
void	parse_savetxture(char **info, t_file *fdata);
int		parse_savecolor(char **info, t_file *fdata);

// ./src/parser/parser_map.c
void	parse_map(t_file *fdata, t_list *list);
int		save_map(int len, t_file *fdata, t_list *list);

// ./src/parser/display
void	display(t_list *lst);
void	display_data(t_file *fdata);

// ./src/utils/utils_parse.c
int		ft_istexture(char *str);
int		ft_iscolor(char *str);
int		ft_isemptyline(char *str);
t_list	*save_texture(t_list *list, t_file *fdata);
t_list	*save_color(t_list *list, t_file *fdata);

// ./src/utils/utils_lst.c
int		get_lstlen(t_list *list);
int		end_of_map(t_list *list, int len);


#endif
