/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/23 17:11:54 by pajimene         ###   ########.fr       */
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
# define INVALID_MAPCONTENT "Invalid characters in MAP !\n\t the map can \
containt only white spaces, 0, 1, and only one  (N, S, E, W)"
# define INVALID_MAPSHAPE "Invalid map !\n\t The player must be surrounded \
by walls"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# define MLX_CON "\n\nError while initilaizing the mlx\n"
# define MLX_WIN "\n\nError while creating\n"
# define MLX_IMG "\n\nError while creating the image\n"

/*Dimensions*/
# define WIDTH		 1920
# define HEIGHT 	 1020
# define TEX_SIZE	 64
# define SPRITE_SIZE 32
# define TILE_SIZE	 10

/*Colors*/
# define WHITE 0xFFFFFFF
# define BLACK 0x0000000
# define PINK 0xFFB3BA
# define YELLOW 0xFFDFBA
# define GREEN 0xBAE1FF
# define LAVANDE 0xD5BAFF
# define MENTHE 0xBAFFC9
# define RED 0xFF0000
# define RED1 0xFFCCCC
# define RED2 0xFF7F7F
# define GREY 0xD3D3D3
# define GREY_DARK 0xA9A9A9

typedef struct s_data	t_data;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef enum e_dir
{
	NORTH=0,
	EAST=1,
	SOUTH=2,
	WEST=3,
	SPRITE_0=4,
	SPRITE_1=5,
	SPRITE_2=6,
	SPRITE_3=7,
	SPRITE_4=8,
	SPRITE_5=9,
	SPRITE_6=10,
	SPRITE_7=11,
	SPRITE_8=12,
	SPRITE_9=13,
}	t_dir;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb[3];
}	t_rgb;

typedef struct s_bresenham
{
	struct s_point	delta;
	struct s_point	p;
	struct s_point	p_inc;
}	t_bresenham;

typedef struct s_raycast
{
	struct s_point	dir;
	struct s_point	map;
	struct s_point	side;
	struct s_point	delta;
	struct s_point	step;
	struct s_point	y_vertical;
	double			wall_dist;
	double			wall_x;
	int				height;
	int				side_col;
	int				*z_buffer;
}	t_raycast;

typedef struct s_player
{
	char			direction;
	struct s_point	pos;
	struct s_point	dir;
	struct s_point	plane;
	struct s_point	mouse;
	int				hide_mouse;
	double			angle;
	int				ceiling_col;
	int				floor_col;
}	t_player;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_sprite
{
	t_point	pos;
	double	dist;
}	t_sprite;

typedef struct s_spriteray
{
	t_point	ray;
	t_point	trans;
	t_point	draw_start;
	t_point	draw_end;
	t_point	tex;
	double	inv_det;
	int		screen_x;
	int		sprite_height;
	int		sprite_width;
}	t_spriteray;

typedef struct s_minimap
{
	double	size;
	t_point	start;
}	t_minimap;

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
	int		sprite_count;
	t_sprite	*sprite;
}	t_file;

typedef struct s_texture
{
	t_img		*img;
	int			x;
	int			y;
	double		step;
	double		pos;
	int			tex_id;
	int			orientation;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_file		*fdata;
	t_texture	*tex;
	t_img		*img;
	t_file		*file;
	t_player	*p;
	t_raycast	*ray;
	t_minimap	*minimap;
	t_spriteray	*spriteray;
}	t_data;

// added by Pablo

t_file	*init_fdata(void);
t_data	*ft_init_data(t_file *fdata);
/*Mlx*/
int		ft_mlx_init(t_data *data);
//void	ft_events(t_data *data);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/*Maths Utils*/
int		ft_min(int a, int b);
void	ft_draw_circle(t_point center, int radius, int color, t_data *data);

/*Player*/
int		ft_player_init(t_data *data);

/*Minimap*/
void	ft_minimap(t_data *data);

/*Events handlers*/
int		ft_close(t_data *data);
int		ft_key(int keysym, t_data *data);
int		ft_mouse_tk(int x, int y, t_data *data);
int		ft_wall_collision(double x, double y, t_data *data);
void	ft_rotate(t_player *p, double angle);
void	ft_move_up(t_player *p, t_data *data);
void	ft_move_down(t_player *p, t_data *data);
void	ft_move_left(t_player *p, t_data *data);
void	ft_move_right(t_player *p, t_data *data);

/*Raycast*/
void	ft_raycast(t_raycast *ray, t_player *p, t_data *data);

/*Draw*/
void	ft_draw_background(t_data *data);
//void	ft_draw_vertical(int x, t_point y_vertical, int col, t_data *data);
int		ft_render_map(t_data *data);
int		ft_rgb_to_hex(int *rgb);
void	ft_textures_init(t_data *data);
void	ft_bresenham(t_point start, t_point end, t_data *data);

/*Color*/
unsigned int	ft_get_pixel_color(t_img *img, int x, int y);
void			ft_put_pixel_blurred(t_img *img, t_point *p, unsigned int color);

// added by Pierre

// ./src/sprite/
void	ft_transform_sprite(t_data *data, int index);
void	ft_calc_width_height(t_data *data);
void	ft_draw_sprites(t_data *data);
void	ft_sort_sprites_by_dist(t_data *data);
void		ft_animate_sprite(t_data *data);

// ./src/parser/parser.c
void	parser_exit(t_file *fdata, char *exmessage, int exno);

// ./src/parser/parser.c
void	parser(int argc, char **argv, t_file *fdata);
t_list	*parse_header(t_file *data, t_list *list);
void	ft_parse_sprites(t_file *fdata);

// ./src/parser/parse_save.c
void	parse_savetxture(char **info, t_file *fdata);
int		parse_savecolor(char **info, t_file *fdata);

// ./src/parser/parser_map.c
void	parse_map(t_file *fdata, t_list *list);
int		is_valid_zero(int x, int y, char **map);
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

// ./src/utils_parse2.c
int		is_valid_door(int x, int y, char **map);

// ./src/utils/utils_lst.c
int		get_lstlen(t_list *list);
int		end_of_map(t_list *list, int len);
void	ft_free_tab(int	**tab);

// ./src/animation/init_animation.c
//t_animation		*init_animation(int width, int height, int delay);
//t_animation		*slice_sprite(t_data *data, int frames, int delay);

#endif
