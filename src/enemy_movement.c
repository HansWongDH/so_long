/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:09:43 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:34:23 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isvalidenemy(t_info *info, int i, int j, int m)
{
	if (info->map[i + m][j] == '1' || info->map[i + m][j] == 'C')
		return (0);
	if (info->map[i + m][j] == 'P')
	{
		info->death = 1;
		return (1);
	}
	return (1);
}

void	enemy_movement(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'A')
	{
		if (!isvalidenemy(info, i, j, 1))
			info->map[i][j] = 'a';
		else if (isvalidenemy(info, i, j, 1))
		{
			info->map[i][j] = '0';
			info->map[i + 1][j] = 'A';
		}
	}
	if (info->map[i][j] == 'a')
	{
		if (!isvalidenemy(info, i, j, -1))
			info->map[i][j] = 'A';
		else if (isvalidenemy(info, i, j, -1))
		{
			info->map[i][j] = '0';
			info->map[i - 1][j] = 'a';
		}
	}
}

void	set_delay(t_info *info, int i, int j)
{
	static int	p;

	if (p == 60)
	{
		enemy_movement(info, i, j);
		p = 0;
	}
	p++;
}

void	enemy_animation(t_info info, int i, int j)
{
	static int	p;

	if (p < 30)
		mlx_put_image_to_window(info.mlx, info.win, info.e1, j * 32, i * 32);
	if (p >= 30 && p < 60)
		mlx_put_image_to_window(info.mlx, info.win, info.e2, j * 32, i * 32);
	if (p >= 60 && p < 90)
		mlx_put_image_to_window(info.mlx, info.win, info.e3, j * 32, i * 32);
	if (p >= 90 && p <= 120)
	{
		if (p == 120)
			p = 0;
		mlx_put_image_to_window(info.mlx, info.win, info.e4, j * 32, i * 32);
	}
	p++;
}

void	draw_enemy(t_info *info)
{
	int			i;
	int			j;

	i = 0;
	if (info->death == 1)
	{
		ft_putstr_fd("You died\n", 1);
		endgame(info);
	}
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'A' || info->map[i][j] == 'a')
			{
				set_delay(info, i, j);
				enemy_animation(*info, i, j);
			}
			j++;
		}
		i++;
	}
}
