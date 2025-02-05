/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:47:28 by slebik            #+#    #+#             */
/*   Updated: 2025/02/05 12:00:19 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	after_floodfill(t_coord *map, char **copy, int i, int j)
{
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
	return (1);
}

int	soft_free(t_data *data)
{
	ft_free_tab(data->map->map);
	free (data->map);
	free (data);
	return (0);
}
