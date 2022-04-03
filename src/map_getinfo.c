/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:00:47 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/03 17:00:13 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	initialize_info(t_info *vars)
// {
// 	vars->mlx = NULL;
// 	vars->win = NULL;
// 	vars->map = NULL;
// 	vars->x = 0;
// 	vars->y = 0;
// 	vars->col = 0;
// 	vars->vic = 0;
// 	vars->death = 0;
// 	vars->step = 0;
// }

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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
