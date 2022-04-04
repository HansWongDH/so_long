/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:48:58 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:30:59 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# define A 0
# define W 13
# define S 1
# define D 2
# define ESC 53

typedef struct s_map {
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		player;
	size_t	length;
	int		height;
	int		error;
}	t_map;

typedef struct s_info {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*door;
	void	*empty;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*e1;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*coin;
	char	**map;
	int		x;
	int		y;
	int		col;
	int		vic;
	int		death;
	int		step;
	int		speed;
	char	*stepz;
}				t_info;

int		map_check_vertical(int fd, t_map *map);
void	initialize_info(t_info *info);
void	free2d(char **s);
void	assign_image(t_info *info);
char	**create_map(int fd, t_map *map);
void	initialize_map(t_map *map);
char	**start_map(char **argv, t_map *map_info);
int		draw(t_info *info);
int		valid(t_info *info, int i, int j);
int		keyinput(int keycode, t_info *info);
int		move(t_info *info, int ver, int hor);
void	get_info(t_info *info);
int		endgame(t_info *info);
void	assign_image(t_info *info);
int		create_trgb(int t, int r, int g, int b);
int		error_message(char **map);
int		map_validation(char **map, t_map m);
void	spawn_enemy(t_info *info);
int		isvalidenemy(t_info *info, int i, int j, int m);
void	enemy_movement(t_info *info, int i, int j);
void	draw_enemy(t_info *info);
void	game_init(t_info *info);
#endif