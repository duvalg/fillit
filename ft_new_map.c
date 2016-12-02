/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:32:39 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/02 00:18:00 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_new_map(t_map *map)
{
	t_map	new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_map = (t_map *)ft_memalloc(sizeof(t_map));
	size = map->size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		map->array[i](ft_strnew(size));
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}