/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/30 19:04:48 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include "./structs.h"
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
# define MLX_CON "\n\nError while initilaizing the mlx"
# define MLX_WIN "\n\nError while creating the window"
# define MLX_IMG "\n\nError while creating the image"
# define MLX_ADDR "\n\n Error while creating the image address"

/*States or type*/
# define OPEN		 0
# define CLOSE		 1
# define IS_OPENING  2
# define IS_CLOSING  3
# define SPRITE		 4
# define DOOR		 5

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
# define BLUE 0x779ECB
# define ORANGE 0xF5B895

/*Init*/
t_file	*init_file(t_data *data);
t_data	*ft_init_data(void);

/*Mlx*/
void	ft_mlx_init(t_data *data);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/*Maths Utils*/
int		ft_min(int a, int b);
void	ft_draw_circle(t_point center, int radius, int color, t_data *data);
int		ft_count_row(char **map);
int		ft_count_column(char *map);

/*Player*/
void	ft_player_init(t_data *data);
int		ft_sprite_in_map(t_data *data);

/*Minimap*/
void	ft_minimap(t_data *data);
int		ft_door_status(t_data *data, int y, int x);
int		ft_is_near_door(t_data *data, int i);
int		ft_door_is_opening(t_data *data);
int		ft_door_is_closing(t_data *data);
int		ft_select_door(t_data *data, int y, int x, int i);

/*Events handlers*/
int		ft_close(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_mouse(int x, int y, t_data *data);
int		ft_wall_collision(double x, double y, t_data *data);
void	ft_rotate(t_player *p, double angle);
void	ft_move_up(t_player *p, t_data *data);
void	ft_move_down(t_player *p, t_data *data);
void	ft_move_left(t_player *p, t_data *data);
void	ft_move_right(t_player *p, t_data *data);
void	ft_open_door(t_data *data);
void	ft_close_door(t_data *data);
void	ft_update_motion(t_data *data, t_player *p);
void	ft_speed_up(t_player *p);

/*Raycast*/
void	ft_raycast(t_raycast *ray, t_player *p, t_data *data);
void	ft_dda_door(t_raycast *ray, t_data *data, int i);
void	ft_calculate_wall_door(t_raycast *ray, t_player *p);
void	ft_calculate_door_text(t_data *data, t_raycast *ray, t_elem *elem, int x);
void	ft_apply_texture_color(t_data *data, int id, int x, int y);
void	ft_floor_ceiling_raycast(t_floorcast *floorcast, t_player *p, t_data *data);

/*Draw*/
void	ft_draw_background(t_data *data);
int		ft_render_map(t_data *data);
int		ft_rgb_to_hex(int *rgb);
void	ft_textures_init(t_data *data);
void	ft_bresenham(t_point start, t_point end, t_data *data);
int		ft_color_dark(int color, double factor);
void	ft_draw_cursor(t_data *data);

/*Color*/
unsigned int	ft_get_pixel_color(t_img *img, int x, int y);
void			ft_put_pixel_blurred(t_img *img, t_point *p, unsigned int color);

// added by Pierre

// ./src/sprite/
void	ft_transform_sprite(t_data *data, int index);
void	ft_calc_width_height(t_data *data);
void	ft_draw_sprites(t_data *data, int index);
int		ft_find_nearest_door_index(t_data *data);
void	ft_sort_elem_by_dist(t_data *data);
void	ft_animate_sprite(t_data *data);
void	ft_animate_open_door(t_data *data);
void	ft_animate_close_door(t_data *data);
void	ft_animate_jump(t_data *data);
void	ft_print_door_message(t_data *data);

// ./src/parser/parser.c
void	ft_free_all(t_data *data, char *message, int code);

// ./src/parser/parser.c
void	parser(int argc, char **argv, t_file *file, t_data *data);
t_list	*parse_header(t_file *file, t_list *list, t_data *data);
void	ft_parse_sprites_doors(t_file *file, t_data *data);

// ./src/parser/parse_save.c
void	parse_savetxture(char **info, t_file *file);
int		parse_savecolor(char **info, t_file *file);

// ./src/parser/parser_maopen x, int y, char **map);
void	parse_map(t_file *file, t_list *list, t_data *data);
int		is_valid_zero(int x, int y, char **map);
int		save_map(int len, t_file *file, t_list *list);

// ./src/parser/display
void	display(t_list *lst);
void	display_data(t_file *file);

// ./src/utils/utils_parse.c
int		ft_istexture(char *str);
int		ft_iscolor(char *str);
int		ft_isemptyline(char *str);
t_list	*save_texture(t_list *list, t_file *file);
t_list	*save_color(t_list *list, t_file *file);

// ./src/utils_parse2.c
int		is_valid_door(int x, int y, char **map);

// ./src/utils/utils_lst.c
int		get_lstlen(t_list *list);
int		end_of_map(t_list *list, int len);
void	ft_free_tab(int	**tab);

#endif
