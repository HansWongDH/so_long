/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:18:38 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/01 20:18:06 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_info info, int i, int j)
{
	char	**s;

	s = info.map;
	if (s[i][j] == '1')
		mlx_put_image_to_window(info.mlx, info.win, info.wall, j * 32, i * 32);
	else if (s[i][j] == 'E')
		mlx_put_image_to_window(info.mlx, info.win, info.door, j * 32, i * 32);
	else
		mlx_put_image_to_window(info.mlx, info.win, info.empty, j * 32, i * 32);
}

void	draw_player(t_info info, int i, int j)
{
	mlx_put_image_to_window(info.mlx, info.win, info.player, j * 32, i * 32);
}

void	draw_dynamic(t_info info, int i, int j)
{
	if (info.col > 0)
		mlx_put_image_to_window(info.mlx, info.win, info.coin, j * 32, i * 32);
}

void	draw_enemy(t_info *info, int i, int j)
{
	mlx_put_image_to_window(info->mlx, info->win, info->player, j * 32, i * 32);
}
void	assign_image(t_info *info)
{
	int		h;
	int		w;
	void	*mlx;

	mlx = info->mlx;
	info->wall = mlx_xpm_file_to_image(mlx, "./texture/wall.xpm", &w, &h);
	info->empty = mlx_xpm_file_to_image(mlx, "./texture/empty.xpm", &w, &h);
	info->door = mlx_xpm_file_to_image(mlx, "./texture/exit.xpm", &w, &h);
	info->coin = mlx_xpm_file_to_image(mlx, "./texture/col.xpm", &w, &h);
	info->player = mlx_xpm_file_to_image(mlx, "./texture/player.xpm", &w, &h);
}

int	draw(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '0' && info->enemy == 0)
			{
				info->map[i][j] = 'A';
				info->enemy = 1;
			}
			draw_wall(*info, i, j);
			if (info->map[i][j] == 'C')
				draw_dynamic(*info, i, j);
			if (info->map[i][j] == 'P')
				draw_player(*info, i, j);
			if (info->map[i][j] == 'A')
				draw_enemy(info, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
