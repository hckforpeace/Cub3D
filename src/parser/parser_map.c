/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:05:33 by pbeyloun          #+#    #+#             */
/*   Updated: 2024/10/01 16:06:02 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_playerpos(t_data *data)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = data->map;
	while(tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N' || tab[i][j] == 'S' || tab[i][j] == 'E' || tab[i][j] == 'W')
			{
				data->orientation = tab[i][j];
				data->start[0] = i;
				data->start[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// the (char **) will contain an array of a size 
int	save_map(int len, t_data *data, t_list *list)
{
	int i;

	data->map = (char **)malloc(sizeof(char) * (len + 1));
	data->map[len] = NULL;
	i = 0;
	while (i < len)
	{
		if (i == 13)
			printf("%s\n", (char *)list->content);
		data->map[i] = (char *)malloc(sizeof(char) * (ft_strlen((char *)list->content) + 1));
		if (!data->map[i])
			return (i);
		ft_strcpy(data->map[i], (char *)list->content);
		list = list->next;
		i++;
	}
	return (-1);
}

int	is_valid_zero(int x, int y, char **map)
{
	if (y == 0 || x == 0)
		return (0);
	else if (map[x][y + 1] == ' ' || map[x][y + 1] == '\0' || map[x][y + 1] == '\n')
		return (0);
	else if (map[x][y - 1] == ' ' || map[x][y - 1] == '\0' || map[x][y - 1] == '\n')
		return (0);
	else if (map[x + 1][y] == ' ' || map[x + 1][y] == '\0' || map[x + 1][y] == '\n')
		return (0);
	else if (map[x - 1][y] == ' ' || map[x - 1][y] == '\0' || map[x - 1][y] == '\n')
		return (0);
	else
		return (1);
}

// funtion not needed if the position value is equal to ' ' it's wrong !
/* int	is_valid_space(int x, int y, char **map)
{
} */

/* int	valid_one(int x, int y, char **map)
{
	
} */

int	map_flood_fill(char **tab, int x, int y)
{
	printf("flood filling tab[x][y]: %c \n", tab[x][y]);
	// return (1);
	if (x < 0 || y < 0 || tab[x][y] == '\0' || tab[x][y] == '\n' || tab[x][y] == '1')
		return (1);
	else if (tab[x][y] == '0' && !is_valid_zero(x, y, tab))
		return (0);
	int u = map_flood_fill(tab, x + 1, y);
	int d = map_flood_fill(tab, x - 1, y);
	int l = map_flood_fill(tab, x, y + 1); 
	int r = map_flood_fill(tab, x, y - 1);
	return (u && d && l && r);	
}

int	parse_map(t_data *data, t_list *list)
{
	int	len;

	len = get_lstlen(list);
	if (len == 0)
		return (0);
	if (save_map(len, data, list) != -1 || !set_playerpos(data))
		return (printf("problems"), 0);
	if (map_flood_fill(data->map, data->start[0], data->start[1]))
		printf("the map is valid\n");
	else
		printf("the map is invalid\n");
	return (1);
}
