/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:10:12 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/03 18:30:42 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		info.map = start_map(argv, &m);
		if (!info.map)
			return (0);
	}
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, m.length * 32, m.height * 32, "Game");
	assign_image(&info);
	get_info(&info);
	draw(&info);
	mlx_key_hook(info.win, keyinput, &info);
	mlx_hook(info.win, 17, 1L << 1, endgame, &info);
	mlx_loop_hook(info.mlx, draw, &info);
	mlx_loop(info.mlx);
}
