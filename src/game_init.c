/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:18:38 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/03 17:04:09 by wding-ha         ###   ########.fr       */
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
	if (info.col > 0 && s[i][j] == 'C')
		mlx_put_image_to_window(info.mlx, info.win, info.coin, j * 32, i * 32);
}

void	render_menu(t_info info, int i, int j)
{
	int	p;

	p = 0;
	while (p < j)
	{
		mlx_put_image_to_window(info.mlx, info.win, info.empty, p * 32, i * 32);
		p++;
	}
}

void	draw_player(t_info info, int i, int j)
{
	mlx_put_image_to_window(info.mlx, info.win, info.player, j * 32, i * 32);
}



// void	draw_enemy(t_info *info, int i, int j)
// {
// 	if (info->map[i][j] == 'A')
// 	{
// mlx_put_image_to_window(info->mlx, info->win, info->player, j * 32, i * 32);
// 	}
// }

int	draw(t_info *info)
{
	int		i;
	int		j;
	int		c;

	c = create_trgb(0, 255, 255, 255);
	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			draw_wall(*info, i, j);
			if (info->map[i][j] == 'P')
				draw_player(*info, i, j);
			j++;
		}
		i++;
	}
	render_menu(*info, i, j);
	mlx_string_put(info->mlx, info->win, j * 16, i * 32, c, info->stepz);
	usleep(10000);
	return (1);
}
