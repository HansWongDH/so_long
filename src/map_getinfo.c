/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:00:47 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:22:49 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	info->p1 = mlx_xpm_file_to_image(mlx, "./texture/player1.xpm", &w, &h);
	info->p2 = mlx_xpm_file_to_image(mlx, "./texture/player2.xpm", &w, &h);
	info->p3 = mlx_xpm_file_to_image(mlx, "./texture/player3.xpm", &w, &h);
	info->p4 = mlx_xpm_file_to_image(mlx, "./texture/player4.xpm", &w, &h);
	info->e1 = mlx_xpm_file_to_image(mlx, "./texture/e1.xpm", &w, &h);
	info->e2 = mlx_xpm_file_to_image(mlx, "./texture/e2.xpm", &w, &h);
	info->e3 = mlx_xpm_file_to_image(mlx, "./texture/e3.xpm", &w, &h);
	info->e4 = mlx_xpm_file_to_image(mlx, "./texture/e4.xpm", &w, &h);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
