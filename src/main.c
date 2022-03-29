/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:10:12 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/29 18:29:50 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_height;
	int		img_width;

	img_height = 480;
	img_width = 800;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img_width, img_height, "Hello world!");
	img = mlx_xpm_file_to_image(mlx_win, "./imgs.xpm", &img_width, &img_height);
	mlx_put_image_to_window (mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}