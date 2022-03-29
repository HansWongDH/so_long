/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:50:53 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/29 19:41:21 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	new_tile(char c, int length, int height)
{
	t_tile	*new;

	new = malloc(sizeof (t_tile));
	if (c == 1)
	{
		new->file = NULL;
		new->x = 0;
		new->y = 0;
		new->next = NULL;
	}
	return (new);
}

void	add_new_tile(t_tile **tile, t_tile *new)
{
	t_tile	*next;

	if (tile && new)
	{
		if (*tile)
		{
			next = ft_stacklast(*tile);
			next->next = new;
		}
		else
			*tile = new;
	}
}
void	map_info_init(char *s, t_map mapinfo)
{
	t_tile	*tile;
	int		i;
	int		j;

	tile = NULL;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == mapinfo.length)
			j++;
		add_new_tile(&tile,new_tile(s[i], i * 50, j * 50));
		i++;
	}
}