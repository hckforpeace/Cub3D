/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:33 by pierre            #+#    #+#             */
/*   Updated: 2024/09/30 13:37:45 by pbeyloun         ###   ########.fr       */
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		fd;
} t_data;

// added by Pierre

// ./src/parser
int	parser(int argc, char **argv, t_data *data);

// ./src/display
void	display(t_list *lst);

#endif
