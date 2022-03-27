/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:45:25 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/27 19:38:42 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	initialize_map()
{
	t_map	map;
	empty = 0;
	wall = 0;
	collect = 0;
	out = 0;
	player = 0;
	length = 0;
	return (map);
}

int	analyse_map(int fd, t_map *map)
{
	char	*s;

	while (get_next_line(fd, &str) > 0)
	{
		if (map->length == 0)
			map->length = ft_strlen(s);
		else if (map->length != ft_strlen(s))
			return (0);
		map->emptyy = 
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	t_map	*map;

	map =initialize_map();
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		analyse_map(fd, &map);
	}
}