/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:10:12 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 20:27:46 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>


int	main(int argc, char **argv)
{
	char	**map;
	t_map	map_info;
	int		i;
	t_vars	vars;

	i = 0;
	map = NULL;
	initialize_map(&map_info);
	if (argc > 1)
		vars.map = start_map(argv, &map_info);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map_info.length * 32, map_info.height * 32, "Hello world!");
	get_info(&vars);
	draw(vars);
	mlx_key_hook(vars.win, keyinput, &vars);
	mlx_loop(vars.mlx);
}
