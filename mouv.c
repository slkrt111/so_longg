/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:32:39 by slebik            #+#    #+#             */
/*   Updated: 2025/02/01 12:32:39 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top(t_data *data)
{
	find_p(data);
	if (data->map->map[data->pos.y - 1][data->pos.x] != '1')
	{	
		top2(data);
	}
}

void	top2(t_data *data)
{
	if (!(data->map->map[data->pos.y - 1][data->pos.x] == 'E'))
	{
		if (data->map->map[data->pos.y - 1][data->pos.x] == 'M')
		{
			ft_printf("game over\n");
			destroy_all(data);
		}
		data->map->map[data->pos.y - 1][data->pos.x] = 'P';
		data->map->map[data->pos.y][data->pos.x] = '0';
		data->count += 1;
		ft_printf("Mouv : %d\n", data->count);
		data->img.img_player = data->img.img_playerup;
	}
	else
	{
		if (count_c(data->map, 'C') == 0)
		{
			ft_printf("the end\n");
			destroy_all(data);
		}
	}
}

void	down(t_data *data)
{
	find_p(data);
	if (data->map->map[data->pos.y + 1][data->pos.x] != '1')
	{
		down2(data);
	}
}

void	down2(t_data *data)
{
	if (!(data->map->map[data->pos.y + 1][data->pos.x] == 'E'))
	{
		if (data->map->map[data->pos.y + 1][data->pos.x] == 'M')
		{
			ft_printf("game over\n");
			destroy_all(data);
		}
		data->map->map[data->pos.y + 1][data->pos.x] = 'P';
		data->map->map[data->pos.y][data->pos.x] = '0';
		data->count += 1;
		ft_printf("Mouv : %d\n", data->count);
		data->img.img_player = data->img.img_playerdown;
	}
	else
	{
		if (count_c(data->map, 'C') == 0)
		{
			ft_printf("the end\n");
			destroy_all(data);
		}
	}
}

void	left(t_data *data)
{
	find_p(data);
	if (data->map->map[data->pos.y][data->pos.x - 1] != '1')
	{
		left2(data);
	}
}
