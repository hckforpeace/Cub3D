/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 21:34:18 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define INPUT_ERROR "wrong input:\n\n expected ./cub3d file_name.cub\n"
# define INVALIDFD_ERROR "invalid file:\n\n expected ./cub3d file_name.cub\n"
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct s_data
{
	t_list	*fd_list;
	int		crgb[3];
	int		frgb[3];
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		fd;
} t_data;

// added by Pierre

// ./src/parser/parser.c
int		parser(int argc, char **argv, t_data *data);
int		parse_header(t_data *data, t_list *list);

// ./src/parser/parse_save.c
void	parse_savetxture(char **info, t_data *data);
int		parse_savecolor(char **info, t_data *data);

// ./src/parser/display
void	display(t_list *lst);
void	display_data(t_data *data);

// ./src/utils/utils_parse.c
int		ft_istexture(char *str);
int		ft_iscolor(char *str);
int		ft_isemptyline(char *str);
t_list	*save_texture(t_list *list, t_data *data);
t_list	*save_color(t_list *list, t_data *data);

#endif
