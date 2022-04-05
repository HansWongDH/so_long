/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:18:38 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/06 03:30:46 by wding-ha         ###   ########.fr       */
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
	static int	p;

	if (p < 15)
		mlx_put_image_to_window(info.mlx, info.win, info.p1, j * 32, i * 32);
	if (p >= 15 && p < 30)
		mlx_put_image_to_window(info.mlx, info.win, info.p2, j * 32, i * 32);
	if (p >= 30 && p < 45)
		mlx_put_image_to_window(info.mlx, info.win, info.p3, j * 32, i * 32);
	if (p >= 45 && p <= 60)
	{
		if (p == 60)
			p = 0;
		mlx_put_image_to_window(info.mlx, info.win, info.p4, j * 32, i * 32);
	}
	p++;
}

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
			if (info->map[i][j] == 'P' && info->death == 0)
				draw_player(*info, i, j);
			j++;
		}
		i++;
	}
	draw_enemy(info);
	render_menu(*info, i, j);
	if (info->stepz)
		mlx_string_put(info->mlx, info->win, j * 16, i * 32, c, info->stepz);
	return (1);
}

void	game_init(t_info *info)
{
	assign_image(info);
	spawn_enemy(info);
	get_info(info);
	draw(info);
	mlx_key_hook(info->win, keyinput, info);
	mlx_hook(info->win, 17, 1L << 1, endgame, info);
	mlx_loop_hook(info->mlx, draw, info);
}
