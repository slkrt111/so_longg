/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:55:00 by slebik            #+#    #+#             */
/*   Updated: 2025/01/21 12:55:00 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct img_s
{
	void	*img_back;
	void	*img_player;
	void	*img_playerleft;
	void	*img_playerright;
	void	*img_playerup;
	void	*img_playerdown;
	void	*img_end;
	void	*img_end2;
	void	*img_wall;
	void	*img_collect;
	void	*img_enemy;
	int		lon;
	int		lar;
	char	*player;
	char	*playerleft;
	char	*playerright;
	char	*playerdown;
	char	*playerup;
	char	*back;
	char	*wall;
	char	*collect;
	char	*end;
	char	*end2;
	char	*enemy;
}				t_img;

typedef struct cnt_s
{
	char	end;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_coord
{
	char			**map;
	char			*info;
	int				x;
	int				y;
}			t_coord;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		lar;
	int		lon;
	t_coord	*map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}				t_data;



char	*get_next_line(int fd);
int		is_nl(char *str);
int		n_len(int n);
char	*check_limit(int nb);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(const char *str);
void	fline(char *line);
int		read_to_buffer(int fd, char *buffer);
char	*update_line(char *line, char *buffer);
void	ft_lstclear(t_coord **lst);
t_coord	*ft_lstnew(void *content);
void	ft_lstadd_back(t_coord **lst, t_coord *new);
t_coord	*ft_lstlast(t_coord *lst);
t_coord	*parsing(int fd);
int		is_rectangle(t_coord *map);
int		valide_char(t_coord *map);
int		doublon_char(t_coord *map, char a, char b);
int		outline1(t_coord *map);
int		outline2(t_coord *map);
void 	flood_fill(char **map, int x, int y);
char	**copy_map(char **map, int lines);
int 	find_x(t_coord *map, char find);
int 	find_y(t_coord *map, char find);
void	ft_free_tab(char **tab);
int		map_valid(t_coord *map);
int		min_item(t_coord *map, char a);
void	print_img(t_data *data, void *img, int x, int y);
void	render_1(t_data *data);
void	set_img(t_data *data);
void	set_img2(t_data *data);
int		verif_all(t_coord *map);
void	render_2(t_data *data);
void	render_3(t_data *data);
int		render_all(t_data *data);
void	find_p(t_data *data);
void 	down(t_data *data);
void 	top(t_data *data);
void 	left(t_data *data);
void 	right(t_data *data);
int		key_press(int keysym, t_data *data);
int		count_c(t_coord *map, char a);
void	destroy_all(t_data *data);






#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif