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
			x++;
		}
		y++;
	}
}

void	render_3(t_data *data)
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

int	render_all(t_data *data)
{
	char	*mouv;
	char	*phrase;
	char	*final;

	render_1(data);
	render_2(data);
	render_3(data);
	mouv = ft_itoa(data->count);
	phrase = " nombre de mouvement : ";
	final = ft_strjoin(ft_strdup(phrase), mouv);
	mlx_string_put(data->mlx_ptr, data->mlx_win, data->map->x * 35,
		data->map->y * 5, 0xFFFFFF, final);
	free(mouv);
	free(final);
	return (1);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		img, data->lon * x, data->lar * y);
}
