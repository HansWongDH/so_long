/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:18:38 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 19:53:41 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(char **s, t_vars vars, int i, int j)
{
	void	*wall;
	void	*empty;
	int		p_width;
	int		p_height;

	wall = mlx_xpm_file_to_image(vars.mlx, "./texture/wall.xpm", &p_width, &p_height);
	empty = mlx_xpm_file_to_image(vars.mlx, "./texture/empty.xpm", &p_width, &p_height);
	if (s[i][j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, wall, j * 32, i * 32);
	else
		mlx_put_image_to_window(vars.mlx, vars.win, empty, j * 32, i * 32);
}

void	draw_player(t_map *map_info, t_vars vars, int i, int j)
{
	void	*player;
	int		p_height;
	int		p_width;

	player = mlx_xpm_file_to_image(vars.mlx, "./texture/player.xpm", &p_width, &p_height);
	mlx_put_image_to_window(vars.mlx, vars.win, player, j * 32, i * 32);
	map_info->x = j;
	map_info->y = i;
}

void	draw_dynamic(t_vars vars, int i, int j)
{
	void	*door;
	int		p_height;
	int		p_width;

	door = mlx_xpm_file_to_image(vars.mlx, "./texture/exit.xpm", &p_width, &p_height);
	mlx_put_image_to_window(vars.mlx, vars.win, door, j * 32, i * 32);
}
void	draw(char **s, t_vars vars, t_map *map_info)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			draw_wall(s, vars, i, j);
			if (s[i][j] == 'E')
				draw_dynamic(vars, i, j);
			if (s[i][j] == 'P')
				draw_player(map_info, vars, i, j);
			j++;
		}
		i++;
	}
}
