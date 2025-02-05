/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:44:03 by slebik            #+#    #+#             */
/*   Updated: 2025/02/05 13:45:13 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img2(t_data *data)
{
	data->img.playerright = "./ressources/spidermanright.xpm";
	data->img.end = "./ressources/end.xpm";
	data->img.enemy = "./ressources/enemy.xpm";
	data->img.img_enemy = mlx_xpm_file_to_image(data->mlx_ptr, data->img.enemy,
			&(data->lar), &(data->lon));
	data->img.img_end = mlx_xpm_file_to_image(data->mlx_ptr, data->img.end,
			&(data->lar), &(data->lon));
	data->img.img_playerright = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.playerright, &(data->lar), &(data->lon));
}
