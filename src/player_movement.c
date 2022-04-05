/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:08:36 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/05 14:20:51 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_info(t_info *info)
{
	int		i;
	int		j;
	char	**s;

	info->col = 0;
	s = info->map;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
			{
				info->x = j;
				info->y = i;
			}
			if (s[i][j] == 'C')
				info->col++;
			j++;
		}
		i++;
	}
}

int	endgame(t_info *info)
{
	mlx_destroy_image(info->mlx, info->empty);
	mlx_destroy_image(info->mlx, info->wall);
	mlx_destroy_image(info->mlx, info->p1);
	mlx_destroy_image(info->mlx, info->p2);
	mlx_destroy_image(info->mlx, info->p3);
	mlx_destroy_image(info->mlx, info->p4);
	mlx_destroy_image(info->mlx, info->coin);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_image(info->mlx, info->e1);
	mlx_destroy_image(info->mlx, info->e2);
	mlx_destroy_image(info->mlx, info->e3);
	mlx_destroy_image(info->mlx, info->e4);
	free2d(info->map);
	exit(0);
	return (0);
}

int	move(t_info *info, int ver, int hor)
{
	if (valid(info, info->y + ver, info->x + hor) && info->vic == 0)
	{
		if (info->map[info->y + ver][info->x + hor] == 'E' && info->col == 0)
		{
			write(1, "You Win\n", 8);
			info->vic = 1;
			endgame(info);
		}
		info->map[info->y][info->x] = '0';
		info->map[info->y + ver][info->x + hor] = 'P';
		get_info(info);
		info->step++;
		if (info->stepz)
			free(info->stepz);
		info->stepz = ft_itoa(info->step);
	}
	return (1);
}

int	keyinput(int keycode, t_info *info)
{
	if (keycode == A)
		move(info, 0, -1);
	if (keycode == W)
		move(info, -1, 0);
	if (keycode == S)
		move(info, 1, 0);
	if (keycode == D)
		move(info, 0, 1);
	if (keycode == ESC)
		endgame(info);
	return (0);
}
