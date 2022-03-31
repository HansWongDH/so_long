/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:48:58 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 20:43:14 by wding-ha         ###   ########.fr       */
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
	char	**map;
	int		x;
	int		y;
	int		col;
}				t_vars;

int		map_check_vertical(int fd, t_map *map);
char	**create_map(int fd, t_map *map);
void	initialize_map(t_map *map);
char	**start_map(char **argv, t_map *map_info);
void	draw(t_vars vars);
int		valid(t_vars vars, int i, int j);
int		keyinput(int keycode, t_vars *vars);
int		move(t_vars *vars, int ver, int hor);
void	get_info(t_vars *vars);
#endif