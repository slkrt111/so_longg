/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:34:59 by slebik            #+#    #+#             */
/*   Updated: 2025/01/29 17:34:59 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	render_1(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == '1')
				print_img(data, data->img.img_wall, x, y);
			if (data->map->map[y][x] == '0')
				print_img(data, data->img.img_back, x, y);
			x++;
		}
		y++;
	}
}

void	render_2(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == 'C')
				print_img(data, data->img.img_collect, x, y);
			if (data->map->map[y][x] == 'E')
				print_img(data, data->img.img_end, x, y);
			if (data->map->map[y][x] == 'M')
				print_img(data, data->img.img_enemy, x, y);
			if (data->map->map[y][x] == 'P')
			{
				data->pos.x = x * 80;
				data->pos.y = y * 80;
				print_img(data, data->img.img_player, x, y);
			}
			x++;
		}
		y++;
	}
}

void	render_all(t_data *data)
{
	char	*mouv;
	char	*phrase;
	char	*final;

	render_1(data);
	render_2(data);
	mouv = ft_itoa(data->count);
	phrase = "Le nombre de mouvement est ";
	final = ft_strjoin(ft_strdup(phrase), mouv);
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->map->x * 60, data->map->y * 5, 0xFFFFFF, final);
}

void	print_img(t_data *data, void *img, int x, int y)
{ 
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, data->lon * x, data->lar * y);
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
