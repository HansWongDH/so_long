/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_getinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:00:47 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/01 14:58:22 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_info(t_info *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->x = 0;
	vars->y = 0;
	vars->col = 0;
	vars->vic = 0;
	vars->death = 0;
	vars->step = 0;
}