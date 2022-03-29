/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:50:53 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/29 18:56:00 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	new_tile(char c, int length, int height)
{
	t_tile	*new;
	
	new = malloc(sizeof (t_tile));
	if (c == 1)
	{
		new->file = "./wall.xpm";
		new->x = length;
		new->y = height;
		new->next = NULL;
	}
}
void	map_info_init()