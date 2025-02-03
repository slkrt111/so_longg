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

void	destroy_all(t_data *data)
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

void	set_img(t_data *data)
{
	data->img.back = "./ressources/back.xpm";
	data->img.wall = "./ressources/wall.xpm";
	data->img.collect = "./ressources/collect.xpm";
	data->img.player = "./ressources/spiderman.xpm";
	data->img.playerup = "./ressources/spidermanup.xpm";
	data->img.playerdown = "./ressources/spidermandown.xpm";
	data->img.playerleft = "./ressources/spidermanleft.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->lar), &(data->lon));
	data->img.img_back = mlx_xpm_file_to_image(data->mlx_ptr, data->img.back,
			&(data->lar), &(data->lon));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->lar), &(data->lon));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->lar), &(data->lon));
	data->img.img_playerleft = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.playerleft, &(data->lar), &(data->lon));
	data->img.img_playerup = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.playerup, &(data->lar), &(data->lon));
	data->img.img_playerdown = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.playerdown, &(data->lar), &(data->lon));
}

void	set_img2(t_data *data)
{
	data->img.playerright = "./ressources/spidermanright.xpm";
	data->img.end = "./ressources/end.xpm";
	data->img.end2 = "./ressources/end2.xpm";
	data->img.enemy = "./ressources/enemy.xpm";
	data->img.img_enemy = mlx_xpm_file_to_image(data->mlx_ptr, data->img.enemy,
			&(data->lar), &(data->lon));
	data->img.img_end = mlx_xpm_file_to_image(data->mlx_ptr, data->img.end,
			&(data->lar), &(data->lon));
	data->img.img_end2 = mlx_xpm_file_to_image(data->mlx_ptr, data->img.end2,
			&(data->lar), &(data->lon));
	data->img.img_playerright = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.playerright, &(data->lar), &(data->lon));
}
