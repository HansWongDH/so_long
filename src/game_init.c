/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:18:38 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 20:36:04 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(char **s, t_vars vars, int i, int j)
{
	void	*wall;
	void	*empty;
	void	*door;
	int		p_width;
	int		p_height;

	wall = mlx_xpm_file_to_image(vars.mlx, "./texture/wall.xpm", &p_width, &p_height);
	empty = mlx_xpm_file_to_image(vars.mlx, "./texture/empty.xpm", &p_width, &p_height);
	door = mlx_xpm_file_to_image(vars.mlx, "./texture/exit.xpm", &p_width, &p_height);
	if (s[i][j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, wall, j * 32, i * 32);
	else if (s[i][j] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win, door, j * 32, i * 32);
	else
		mlx_put_image_to_window(vars.mlx, vars.win, empty, j * 32, i * 32);
}

void	draw_player(t_vars vars, int i, int j)
{
	void	*player;
	int		p_height;
	int		p_width;

	player = mlx_xpm_file_to_image(vars.mlx, "./texture/player.xpm", &p_width, &p_height);
	mlx_put_image_to_window(vars.mlx, vars.win, player, j * 32, i * 32);
}

void	draw_dynamic(t_vars vars, int i, int j)
{
	void	*col;
	int		p_height;
	int		p_width;

	col = mlx_xpm_file_to_image(vars.mlx, "./texture/col.xpm", &p_width, &p_height);
	mlx_put_image_to_window(vars.mlx, vars.win, col, j * 32, i * 32);
}
void	draw(t_vars vars)
{
	int		i;
	int		j;
	char	**s;

	s = vars.map;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			draw_wall(s, vars, i, j);
			if (s[i][j] == 'C')
				draw_dynamic(vars, i, j);
			if (s[i][j] == 'P')
				draw_player(vars, i, j);
			j++;
		}
		i++;
	}
}
