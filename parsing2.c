/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:21:46 by slebik            #+#    #+#             */
/*   Updated: 2025/01/27 19:21:46 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	outline2(t_coord *map)
{
	int	i;

	i = 0;
	while (i < map->y - 1)
	{
		if (map->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->y - 1)
	{
		if (map->map[i][map->x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	**copy_map(char **map, int lines)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * lines + 1);
	if (!copy)
		return (NULL);
	while (i < lines)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[lines] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y]
		|| !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == 'E')
	{
		if (map[y][x] == 'E')
			map[y][x] = '1';
		return ;
	}
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P')
	{
		map[y][x] = 'V';
		flood_fill(map, x + 1, y);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x, y - 1);
	}
}

int	map_valid(t_coord *map)
{
	char	**copy;
	int		startx;
	int		starty;
	int		i;
	int		j;

	startx = find_x(map, 'P');
	starty = find_y(map, 'P');
	i = 0;
	copy = copy_map(map->map, map->y); //g enlever les protec !copy pr les lignes
	flood_fill(copy, startx, starty);
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	ft_free_tab(copy);
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
