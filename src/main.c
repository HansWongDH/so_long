/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:10:12 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:31:09 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	m;
	t_info	info;

	initialize_map(&m);
	initialize_info(&info);
	if (argc > 1)
	{
		info.map = start_map(argv, &m);
		if (!info.map)
			return (0);
	}
	if (!map_validation(info.map, m))
	{
		error_message(info.map);
		return (0);
	}
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, m.length * 32, m.height * 32, "Game");
	game_init(&info);
	mlx_loop(info.mlx);
}
