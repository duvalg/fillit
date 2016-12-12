/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:42:50 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/11 04:03:42 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit		*get_map(t_fillit *fillit)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!(MAP = (char ***)malloc(sizeof(char **) * fillit->pieces)))
		ft_error(fillit, ERROR);
	while (i < fillit->pieces)
	{
		if (!(MAP[i] = ft_strsplit(ft_strsub(BUF, i * 21, 21), '\n')))
			ft_error(fillit, ERROR);
		i++;
	}
	return (fillit);
}
