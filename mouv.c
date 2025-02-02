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
#include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>


void top(t_data *data)
{
	find_p(data);

	if(data->map->map[data->pos.y - 1][data->pos.x] != '1')
	{	
		if(!(data->map->map[data->pos.y - 1][data->pos.x] == 'E'))
		{
			if (data->map->map[data->pos.y - 1][data->pos.x] == 'M')
			{
				printf("game over\n");
				destroy_all(data);
			}
			if(count_c(data->map, 'C') == 0)
				data->img.img_end = data->img.img_end2;
			data->map->map[data->pos.y - 1][data->pos.x] = 'P';
			data->map->map[data->pos.y][data->pos.x] = '0';
			data->count += 1;
			printf("Mouv : %d\n", data->count);
			data->img.img_player = data->img.img_playerup;
		}
		else
		{
			if(count_c(data->map, 'C') == 0)
			{
				data->img.img_end = data->img.img_end2;
				printf("the end\n");
				destroy_all(data);
			}
		}
	}
}

void down(t_data *data)
{
	find_p(data);
	
	if(data->map->map[data->pos.y + 1][data->pos.x] != '1')
	{
		if(!(data->map->map[data->pos.y + 1][data->pos.x] == 'E'))
		{
			if (data->map->map[data->pos.y + 1][data->pos.x] == 'M')
			{
				printf("game over\n");
				destroy_all(data);
			}
			if(count_c(data->map, 'C') == 0)
				data->img.img_end = data->img.img_end2;
			data->map->map[data->pos.y + 1][data->pos.x] = 'P';
			data->map->map[data->pos.y][data->pos.x] = '0';
			data->count += 1;
			printf("Mouv : %d\n", data->count);
			data->img.img_player = data->img.img_playerdown;
		}
		else
		{
			if(count_c(data->map, 'C') == 0)
			{
				printf("the end\n");
				destroy_all(data);
			}
		}
	}
}

void left(t_data *data)
{
	find_p(data);
	
	if(data->map->map[data->pos.y][data->pos.x - 1] != '1')
	{
		if(!(data->map->map[data->pos.y][data->pos.x - 1] == 'E'))
		{
			if (data->map->map[data->pos.y][data->pos.x - 1] == 'M')
			{
				printf("game over\n");
				destroy_all(data);
			}
			if(count_c(data->map, 'C') == 0)
				data->img.img_end = data->img.img_end2;
			data->map->map[data->pos.y][data->pos.x - 1] = 'P';
			data->map->map[data->pos.y][data->pos.x] = '0';
			data->count += 1;
			printf("Mouv : %d\n", data->count);
			data->img.img_player = data->img.img_playerleft;
		}
		else
		{
			if(count_c(data->map, 'C') == 0)
			{
				printf("the end\n");
				destroy_all(data);
			}
		}
	}
}

void right(t_data *data)
{
	find_p(data);
	if(data->map->map[data->pos.y][data->pos.x + 1] != '1')
	{
		
		if(!(data->map->map[data->pos.y][data->pos.x + 1] == 'E'))
		{
			if (data->map->map[data->pos.y][data->pos.x + 1] == 'M')
			{
				printf("game over\n");
				destroy_all(data);
			}
			if(count_c(data->map, 'C') == 0)
				data->img.img_end = data->img.img_end2;
			data->map->map[data->pos.y][data->pos.x + 1] = 'P';
			data->map->map[data->pos.y][data->pos.x] = '0';
			data->count += 1;
			printf("Mouv : %d\n", data->count);
			data->img.img_player = data->img.img_playerright;
		}
		else
		{
			if(count_c(data->map, 'C') == 0)
			{
				printf("the end\n");
				destroy_all(data);
			}
		}
	}
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape) //• Cliquer sur la croix en haut de la fenêtre doit fermer celle-ci et quitter le programme proprement.
		destroy_all(data);
	if (keysym == XK_w)
		top(data);
	if (keysym == XK_d)
		right(data);
	if (keysym == XK_a)
		left(data);
	if (keysym == XK_s)
		down(data);
	return (0);
}
