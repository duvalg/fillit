/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:14:02 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/03 12:34:02 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(map->array);
	map->array = NULL;
	free(map);
	map = NULL;
}
