/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:37 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:02:15 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		return (0);
	if (info->map[i][j] == 'E' && info->col > 0)
		return (0);
	if (info->map[i][j] == 'a' || info->map[i][j] == 'A')
	{
		info->death = 1;
		return (0);
	}
	if (info->death == 1)
		return (0);
	return (1);
}

void	free2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s[i]);
	free(s);
}

void	initialize_info(t_info *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map = NULL;
	info->wall = NULL;
	info->empty = NULL;
	info->door = NULL;
	info->p1 = NULL;
	info->p2 = NULL;
	info->p3 = NULL;
	info->p4 = NULL;
	info->coin = NULL;
	info->e1 = NULL;
	info->x = 0;
	info->y = 0;
	info->col = 0;
	info->vic = 0;
	info->death = 0;
	info->speed = 0;
	info->step = 0;
	info->stepz = NULL;
}
