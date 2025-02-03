/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:56:44 by slebik            #+#    #+#             */
/*   Updated: 2025/01/21 12:56:44 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*parsing(int fd)
{
	int		i;
	char	*info;
	t_coord	*map;

	map = malloc(1 * sizeof(t_coord));
	if (!map)
		return (NULL);
	map->map = malloc(10000 * sizeof(char *));
	i = 0;
	while ((info = get_next_line(fd)) != NULL)
	{
		map->map[i] = info;
		i++;
	}
	map->map[i] = NULL;
	return (map);
}

int	is_rectangle(t_coord *map)
{
	int	xstart;

	map->y = 0;
	xstart = strlen(map->map[map->y]) - 2;
	while (map->map[map->y])
	{
		if (map->map[map->y + 1] == NULL)
			map->x = strlen(map->map[map->y]);
		else
			map->x = strlen(map->map[map->y]) - 2;
		if (map->x != xstart)
			return (0);
		map->y++;
	}
	if (map->x == map->y)
		return (0);
	return (1);
}

int	valide_char(t_coord	*map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '\r')
			{
				j++;
				continue ;
			}
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'C'
				&& map->map[i][j] != 'E' && map->map[i][j] != '\n'
				&& map->map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	doublon_char(t_coord *map, char a, char b)
{
	int	i;
	int	j;
	int	count_a;
	int	count_b;

	i = 0;
	count_a = 0;
	count_b = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == a)
				count_a++;
			if (map->map[i][j] == b)
				count_b++;
			j++;
		}
		i++;
	}
	if (count_a != 1 || count_b != 1)
		return (0);
	return (1);
}

int	outline1(t_coord *map)
{
	int	line_len;
	int	i;

	i = 0;
	line_len = strlen(map->map[0]);
	while (i < line_len - 2)
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < line_len - 2)
	{
		if (map->map[map->y - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
