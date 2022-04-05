/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:50:53 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/06 03:30:02 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->empty = 0;
	map->wall = 0;
	map->collect = 0;
	map->out = 0;
	map->player = 0;
	map->length = 0;
	map->height = 1;
	map->error = 0;
}

int	check_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_validation(char **map, t_map m)
{
	if (!check_wall(map[0]) || !check_wall(map[m.height - 2]))
		return (0);
	if (m.player != 1 || m.out != 1 || m.collect < 1 || m.error == 1)
		return (0);
	return (1);
}

int	check_filetype(char **argv)
{
	char	*file;

	if (ft_strlen(argv[1]) < 5)
		return (0);
	file = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strcmp(file, ".ber"))
	{
		free(file);
		return (0);
	}
	free(file);
	return (1);
}

char	**start_map(char **argv, t_map *map_info)
{
	char	**map;
	int		fd;

	if (!check_filetype(argv))
	{
		ft_putstr_fd("Wrong filetype\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!map_check_vertical(fd, map_info))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	map = create_map(fd, map_info);
	close(fd);
	return (map);
}
