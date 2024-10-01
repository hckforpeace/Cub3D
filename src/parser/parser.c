/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:01:20 by pierre            #+#    #+#             */
/*   Updated: 2024/10/01 14:32:17 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// reads all the content of the file and stores it in a chained list 
static int file_to_list(t_data *data)
{
	char	*line;
	char	*line_trim;

	line = get_next_line(data->fd);
	if (!line)
		return (0);
	while (line)
	{
		line_trim = ft_strtrim(line, " ");
		ft_lstadd_back_b(&data->fd_list, ft_lstnew_b(line_trim, ft_strlen(line_trim)));
		free(line);
		line = get_next_line(data->fd);
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

// general parsing function
int	parser(int argc, char **argv, t_data *data)
{
	t_list *temp;

	if (argc != 2 || !is_valid_file_name(argv[1]))
		return (printf("%s", INPUT_ERROR), 0);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (printf("%s", INVALIDFD_ERROR), 0);
	file_to_list(data);
	temp = parse_header(data, data->fd_list);
	if (!temp)
		return (printf("there is an error in the file"), 0);	
	if (!parse_map(data, temp))
		return (printf("there is an error in the file"), 0);			
	display_data(data);
	return (1);
}
