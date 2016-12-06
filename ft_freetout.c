/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:38:23 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/06 06:21:37 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_fillit	free_map(t_fillit *fillit)
{
	int		i;

	i = 0;
	while (i < MAP)
	{
		free(MAP[i]);
		MAP[i] = NULL;
		i++;
	}
	free(MAP);
	MAP = NULL;
}

t_fillit	ft_free_tetris(t_fillit *fillit)
{
	int		i;

	i = 0;
	while (i < fillit->pieces)
	{
		free(fillit->pieces);
		fillit->pieces = NULL;
		i++;
	}
}
