/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:10:12 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/01 19:40:38 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw2(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win, info->door, 50, 50);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	m;
	int		i;
	t_info	info;

	i = 0;
	map = NULL;
	initialize_map(&m);
	initialize_info(&info);
	if (argc > 1)
		info.map = start_map(argv, &m);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, m.length * 32, m.height * 32, "Game");
	assign_image(&info);
	get_info(&info);
	mlx_key_hook(info.win, keyinput, &info);
	mlx_loop_hook(info.mlx, draw, &info);
	mlx_loop(info.mlx);
}
