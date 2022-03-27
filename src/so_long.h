/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:48:58 by wding-ha          #+#    #+#             */
/*   Updated: 2022/03/27 19:38:40 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map {
	int	empty;
	int	wall;
	int	collect;
	int	out;
	int	player;
	int	length;
}	t_map;

#endif