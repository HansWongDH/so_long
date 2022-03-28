/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:23:37 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/28 14:24:44 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	edge_checking(char **map, int vert)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[vert][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}