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

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	if (ac != 2 || valid_extension(av[1]) == 0)
		return (write(2, "extension or arg error\n", 24), 0);
	data = malloc(sizeof(t_data));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free (data);
		return (write(2, "Error file not found\n", 22), 0);
	}
	data->map = parsing(fd);
	close(fd);
	if (!data->map->map)
		return (0);
	if (verif_all(data->map) == 0)
	{
		soft_free(data);
		return (write(2, "Error\n", 6), 0);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (soft_free(data));
	setandrender(data);
}

void	setandrender(t_data *data)
{	
	set_img(data);
	set_img2(data);
	if (img_valid_name(data) == 0)
	{
		write(2, "Error img no valid\n", 20);
		destroy_all(data);
		return ;
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->map->x * 80,
			data->map->y * 80, "so_long");
	data->count = 0;
	render_all(data);
	mlx_loop_hook(data->mlx_ptr, &render_all, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, destroy_all, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, &key_press, data);
	mlx_loop(data->mlx_ptr);
	destroy_all(data);
}

int	valid_extension(char *param)
{
	int	len;

	if (!param)
		return (0);
	len = ft_strlen(param);
	if (len < 4)
		return (0);
	if (param[len - 1] != 'r' || param[len - 2] != 'e' || param[len - 3] != 'b' || param[len - 4] != '.')
		return (0);
	return (1);
}
