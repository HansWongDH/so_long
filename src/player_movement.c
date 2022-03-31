/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:08:36 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 20:43:44 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	get_info(t_vars *vars)
{
	int		i;
	int		j;
	char	**s;

	vars->col = 0;
	s = vars->map;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
			{
				vars->x = j;
				vars->y = i;
			}
			if (s[i][j] == 'C')
				vars->col++;
			j++;
		}
		i++;
	}
}

int	move(t_vars *vars, int ver, int hor)
{
	if (valid(*vars, vars->y + ver, vars->x + hor))
	{
		if (vars->map[vars->y + ver][vars->x + hor] == 'E' && vars->col == 0)
			write(1, "You Win\n", 9);
		vars->map[vars->y][vars->x] = '0';
		vars->map[vars->y + ver][vars->x + hor] = 'P';
		get_info(vars);
	}	
	draw(*vars);
	return (1);
}

int	keyinput(int keycode, t_vars *vars)
{
	if (keycode == A)
		move(vars, 0, -1);
	if (keycode == W)
		move(vars, -1, 0);
	if (keycode == S)
		move(vars, 1, 0);
	if (keycode == D)
		move(vars, 0, 1);
	return (0);
}
