/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 22:34:26 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define INPUT_ERROR "wrong input:\n\n expected ./cub3d file_name.cub\n"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# define INVALID_MAPCONTENT "Invalid characters in MAP !\n\t the map can containt only white spaces, 0, 1, and only one  (N, S, E, W)"
# define INVALID_MAPSHAPE "Invalid map !\n\t The player must be surrounded by walls"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include "../mlx_linux/mlx.h"

typedef struct	s_img {
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_animation {
	t_list		*frames;
	int			width;
	int			height;
	int			delay;			// How many fps it takes to change animation
	int			_tmp_delay;		// Delay Iterator
	int			current_frame_num;	// Which frame is selected
	long int	last_updated;		// When was the last update
	long int	frame_count;		// The frame count
}		t_animation;

typedef struct s_sprite {
	t_list	*animations;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int	z_index;
}		t_sprite;

typedef	struct s_slice {
	int x;
	int y;
	int width;
	int height;
}	t_slice;


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
	t_img	textures[4];
	void	*mlx;
	void	*mlx_win;
} t_file;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_img		fimg;
	t_sprite	*sprites;
} t_game;

// added by Pierre

// ./src/sprite/
void		load_sprite(t_game *game, char *path_to_srpite, void *mlx);
void		add_frame(t_animation *a, t_slice *slice, t_game *game);
void		draw_sprite(float scale, t_img *sub, t_img *win);



// ./src/parser/parser_init.c
t_file		*init_fdata();

// ./src/parser/parser.c
void		parser_exit(t_file *fdata, char *exmessage, int exno);

// ./src/parser/parser.c
void		parser(int argc, char **argv, t_file *fdata);
t_list		*parse_header(t_file *data, t_list *list);

// ./src/parser/parse_save.c
void		parse_savetxture(char **info, t_file *fdata);
int			parse_savecolor(char **info, t_file *fdata);

// ./src/parser/parser_map.c
void		parse_map(t_file *fdata, t_list *list);
int			save_map(int len, t_file *fdata, t_list *list);

// ./src/parser/display
void		display(t_list *lst);
void		display_data(t_file *fdata);
void 		my_display(t_img *img);

// ./src/utils/utils_parse.c
int			ft_istexture(char *str);
int			ft_iscolor(char *str);
int			ft_isemptyline(char *str);
t_list		*save_texture(t_list *list, t_file *fdata);
t_list		*save_color(t_list *list, t_file *fdata);

// ./src/utils/utils_lst.c
int			get_lstlen(t_list *list);
int			end_of_map(t_list *list, int len);

// ./src/utils/utils_sprite.c
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			mlx_get_pixel_color(t_img *img, int x, int y);

// ./src/animation/init_animation.c
t_animation		*init_animation(int width, int height, int delay);
t_animation		*slice_sprite(t_game *game, t_slice *slice, int frames, int delay);

#endif
