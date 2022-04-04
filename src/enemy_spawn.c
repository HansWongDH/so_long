/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:12:14 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:32:25 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_spawn(t_info *info, int i, int j)
{
	if (info->map[i + 1][j] == '1' && info->map[i - 1][j] == '1')
		return (0);
	while (i > 0)
	{
		if (info->map[i][j] == 'A')
			return (0);
		i--;
	}
	return (1);
}

void	spawn_enemy(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '0' && valid_spawn(info, i, j))
			{		
				if (info->map[i][j + 1] == 'C')
					info->map[i][j] = 'A';
				else if (j > 0 && info->map[i][j - 1] == 'C')
					info->map[i][j] = 'A';
			}
			j++;
		}
		i++;
	}
}
