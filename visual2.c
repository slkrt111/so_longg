/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:30:07 by slebik            #+#    #+#             */
/*   Updated: 2025/02/01 12:30:07 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	count_c(t_coord *map, char a)
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
	return (count_a);
}

void destroy_all(t_data *data)
{
	ft_free_tab(data->map->map);
	mlx_destroy_image(data->mlx_ptr, data->img.img_back);
	mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img.img_end);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_enemy);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	exit (0);
}