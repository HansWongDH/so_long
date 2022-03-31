/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:08:36 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 19:52:11 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	move(char **s, t_map *map_info, int ver, int hor)
{
	if (valid(s, map_info->y + ver, map_info->x + hor))
	{
		s[map_info->y][map_info->x] = '0';
		s[map_info->y + ver][map_info->x + hor] = 'P';
	}
	return (1);
}

int	keyinput(int keycode, char **s, t_map *map_info)
{
	if (keycode == A)
		move(s, map_info, 0, -1);
	if (keycode == W)
		move(s, map_info, 1, 0);
	if (keycode == S)
		move(s, map_info, -1, 0);
	if (keycode == D)
		move(s, map_info, 0, 1);
	return (0);
}
