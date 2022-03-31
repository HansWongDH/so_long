/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:48:58 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 19:48:23 by wding-ha         ###   ########.fr       */
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


typedef struct s_map {
	int	empty;
	int	wall;
	int	collect;
	int	out;
	int	player;
	int	x;
	int	y;
	size_t	length;
	int	height;
}	t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	map_check_vertical(int fd, t_map *map);
char	**create_map(int fd, t_map *map);
void	initialize_map(t_map *map);
char	**start_map(char **argv, t_map *map_info);
void	draw(char **s, t_vars vars, t_map *map_info);
int	valid(char **map, int i, int j);
int	keyinput(int keycode, char **s, t_map *map_info);
int	move(char **s, t_map *map_info, int ver, int hor);
#endif