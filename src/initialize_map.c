/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:50:53 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/31 14:45:50 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**start_map(char **argv , t_map *map_info)
{
	char	*file;
	char	**map;
	int		fd;

	file = ft_substr(argv[1], ft_strlen(argv[1]) - 4, 4);
	if (ft_strcmp(file, ".ber"))
	{
		write(1, "wrong filetype\n", 16);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	map_check_vertical(fd, map_info);
	fd = open(argv[1], O_RDONLY);
	map = create_map(fd, map_info);
	close(fd);
	return (map);
}
