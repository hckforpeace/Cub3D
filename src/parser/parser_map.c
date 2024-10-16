/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:05:33 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/16 13:40:57 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_playerpos(t_file *fdata)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = fdata->map;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E'
				|| tab[i][j] == 'W')
			{
				fdata->orientation = tab[i][j];
				fdata->start[0] = i;
				fdata->start[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_zero(int x, int y, char **map)
{
	if (y == 0 || x == 0)
		return (0);
	else if (map[x][y + 1] == ' ' || map[x][y + 1] == '\0'
		|| map[x][y + 1] == '\n')
		return (0);
	else if (map[x][y - 1] == ' ' || map[x][y - 1] == '\0'
		|| map[x][y - 1] == '\n')
		return (0);
	else if (map[x + 1][y] == ' ' || map[x + 1][y] == '\0'
		|| map[x + 1][y] == '\n')
		return (0);
	else if (map[x - 1][y] == ' ' || map[x - 1][y] == '\0'
		|| map[x - 1][y] == '\n')
		return (0);
	else
		return (1);
}

int	map_flood_fill(char **tab, int x, int y, t_file *fdata)
{
	if (y > fdata->mwidth)
		fdata->mwidth = y;
	if (x < 0 || y < 0 || tab[x][y] == '1' || tab[x][y] == 'R')
		return (1);
	else if ((tab[x][y] == '0' || tab[x][y] == 'N' || tab[x][y] == 's'
		|| tab[x][y] == 'E' || tab[x][y] == 'W' || tab[x][y] == 'S')
		&& !is_valid_zero(x, y, tab))
		return (printf("error at tab[%d][%d]: %c\n", x, y, tab[x][y]), 0);
	if (tab[x][y] == 'D' && !is_valid_door(x, y, tab))
		return (printf("error at tab[%d][%d]: %c\n", x, y, tab[x][y]), 0);
	if (tab[x][y] == '0')
		tab[x][y] = 'R';
	if (tab[x][y] == 's')
		tab[x][y] = 'G';
	if (tab[x][y] == 'D')
		tab[x][y] = 'B';
	return (map_flood_fill(tab, x + 1, y, fdata)
		&& map_flood_fill(tab, x - 1, y, fdata)
		&& map_flood_fill(tab, x, y + 1, fdata)
		&& map_flood_fill(tab, x, y - 1, fdata));
}

// Modified
int	parse_map_aux(t_list *list, int len)
{
	char	*content;
	int		i;
	int		player;

	player = 0;
	while (len-- > 0)
	{
		i = 0;
		content = (char *)list->content;
		while (content[i])
		{
			if (content[i] == 'N' || content[i] == 'E'
				|| content[i] == 'S' || content[i] == 'W')
				player++;
			else if (content[i] != ' ' && content[i] != '0' && content[i] != '1'
				&& content[i] != '\n' && content[i] != '\0' && content[i] != 's'
				&& content[i] != 'D')
				return (0);
			i++;
		}
		list = list->next;
	}
	if (player == 1)
		return (1);
	return (0);
}

void	parse_map(t_file *fdata, t_list *list)
{
	int	len;

	len = get_lstlen(list);
	fdata->mwidth = 0;
	fdata->height = len;
	if (!end_of_map(list, len))
		parser_exit(fdata, "Invalid content\ncharachters after map", 1);
	if (len == 0)
		parser_exit(fdata, "Missing map !", 1);
	if (!parse_map_aux(list, len))
		parser_exit(fdata, INVALID_MAPCONTENT, 1);
	if (save_map(len, fdata, list) != -1 || !set_playerpos(fdata))
		parser_exit(fdata, "UNEXPECTED ERROR", 1);
	if (map_flood_fill(fdata->map, fdata->start[0], fdata->start[1], fdata))
		printf("\n\n\n***the map is valid***\n\n\n");
	else
		parser_exit(fdata, INVALID_MAPSHAPE, 1);
}
