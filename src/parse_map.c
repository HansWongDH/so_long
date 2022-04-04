/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:45:25 by wding-ha          #+#    #+#             */
/*   Updated: 2022/04/04 19:32:48 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_vertical(int fd, t_map *map)
{
	char	buf[1];
	int		i;

	i = 0;
	while (read(fd, buf, 1) > 0)
	{
		i++;
		if (buf[0] == '\n')
			map->height++;
		if (!ft_strchr("01CEP\n", buf[0]))
			return (0);
		if (buf[0] == 'P')
			map->player++;
		if (buf[0] == 'E')
			map->out++;
		if (buf[0] == 'C')
			map->collect++;
	}
	map->height++;
	if (i == 0)
		return (0);
	return (1);
}

char	**create_map(int fd, t_map *map)
{
	char	**s;
	char	*l;
	int		i;

	s = malloc(sizeof(char *) * map->height + 1);
	i = 0;
	while (get_next_line(fd, &l))
	{
		if (map->length == 0)
			map->length = ft_strlen(l);
		else if (map->length != ft_strlen(l))
			map->error = 1;
		if (l[0] != '1' || l[map->length - 1] != '1')
			map->error = 1;
		s[i] = ft_strdup(l);
		free(l);
		i++;
	}
	if (map->length != ft_strlen(l))
		map->error = 1;
	s[i] = ft_strdup(l);
	free(l);
	s[i + 1] = NULL;
	return (s);
}
