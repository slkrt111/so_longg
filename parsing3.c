/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:30:34 by slebik            #+#    #+#             */
/*   Updated: 2025/01/27 19:30:34 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_x(t_coord *map, char find)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == find)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_y(t_coord *map, char find)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == find)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	min_item(t_coord *map, char a)
{
	int	i;
	int	j;
	int	count_a;

	i = 0;
	count_a = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == a)
				count_a++;
			j++;
		}
		i++;
	}
	if (count_a < 1)
		return (0);
	return (1);
}

int	verif_all(t_coord *map)
{
	if (is_rectangle(map) == 0 || valide_char(map) == 0
		|| doublon_char(map, 'P', 'E') == 0 || min_item(map, 'C') == 0
		||outline1(map) == 0 || outline2(map) == 0
		|| map_valid(map) == 0)
		return (0);
	return (1);
}

void	find_p(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
