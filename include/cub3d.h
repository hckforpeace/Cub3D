/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/10/02 15:32:08 by pierre           ###   ########.fr       */
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
} t_file;

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
