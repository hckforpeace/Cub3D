/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:20 by pierre            #+#    #+#             */
/*   Updated: 2024/10/16 15:56:39 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// reads all the content of the file and stores it in a chained list 
static int	file_to_list(t_file *fdata)
{
	char	*line;

	line = get_next_line(fdata->fd);
	if (!line)
		return (0);
	while (line)
	{
		ft_lstadd_back_b(&fdata->fd_list, ft_lstnew_b(ft_strdup(line),
				ft_strlen(line)));
		free(line);
		line = get_next_line(fdata->fd);
	}
	return (1);
}

/* 
	-checks the file name is not empty
	-checks the file name ends with ".cub"
*/
static int	is_valid_file_name(char *filename)
{
	if (!filename || !*filename || *filename == '.')
		return (0);
	while (*filename != '.')
		filename++;
	if (ft_strcmp(filename, ".cub") != 0)
		return (0);
	return (1);
}

static void	reset_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'R')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

// general parsing function
void	parser(int argc, char **argv, t_file *fdata)
{
	t_list	*temp;

	if (argc != 2 || !is_valid_file_name(argv[1]))
		parser_exit(fdata, "invalid filename", 1);
	fdata->fd = open(argv[1], O_RDONLY);
	if (fdata->fd < 0)
		parser_exit(fdata, "failed to open the file !", 1);
	file_to_list(fdata);
	close(fdata->fd);
	temp = parse_header(fdata, fdata->fd_list);
	parse_map(fdata, temp);
	reset_map(fdata->map);
}
