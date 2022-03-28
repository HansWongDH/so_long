/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:45:25 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/28 19:16:55 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	initialize_map(t_map *map)
{
	map->empty = 0;
	map->wall = 0;
	map->collect = 0;
	map->out = 0;
	map->player = 0;
	map->length = 0;
	map->height = 0;
}

int	map_check_vertical(int fd, t_map *map)
{
	char	buf[1];

	while (read(fd, buf, 1) > 0)
	{
		if (buf[0] == '\n' || buf[0] == '\0')
			map->height++;
		if (!ft_strchr("01CEP", buf[0]))
			return (0);
	}
	return (1);
}


char	*create_map(int fd, t_map *map)
{
	char	*s;
	char	*l;

	while (get_next_line(fd, &l) > 0)
	{
		if (map->length == 0)
			map->length = ft_strlen(l);
		else if (map->length != ft_strlen(l))
			return (0);
		if ((l[0] && l[map->length - 1]) != '1')
			return (0);
		s = ft_strjoin(s, l);
	}
	return (s);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*map;
	t_map	*map_info;

	initialize_map(map);
	if (argc > 1)
	{
		if (!ft_strstr(argv[1], ".ber"))
			return (0);
		fd = open(argv[1], O_RDONLY);
		map = create_map(fd, map_info);
		close(fd);
	}
}
