/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:03:41 by slebik            #+#    #+#             */
/*   Updated: 2025/01/22 15:03:41 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

// ouvrir la map passer en argument avec ac av pureeee smr  >>
//leaks
// taille des fonctions >>
//fermer avec clique
// le cas arti >>

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	if (ac != 2)
		return (write(2, "Error\n", 6), 0);
	data = malloc(sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\n", 6), 0);
	data->map = parsing(fd);
	close(fd);
	if (!data->map->map)
		return (0);
	if (verif_all(data->map) == 0)
		return (write(2, "Error\n", 6), 0);


	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->map->x * 80,
			data->map->y * 80, "so_long");
	set_img(data);
	set_img2(data);
	render_all(data);
	mlx_loop_hook(data->mlx_ptr, &render_all, data);
	mlx_hook(data->mlx_win, 17, 1L<<0, &key_press, data);
	mlx_hook(data->mlx_win, 2, 1L<<0, &key_press, data);
	mlx_loop(data->mlx_ptr);
}
