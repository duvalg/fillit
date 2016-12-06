/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:47:25 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/06 06:30:33 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "fillit.h"

t_fillit		ft_new_map(t_fillit *fillit)
{
	if(!(MAP = (char ***)malloc(sizeof(char **) * fillit->pieces + 1)));
	ft_error(fillit, MALLOC);
	while (i < fillit->pieces)
	{
		if(!(MAP[i++] = ft_strsplit(ft_strsub(BUF, i * 21, 21),'\n')))
			ft_error(fillit, MALLOC)
				MAP = NULL;
		return (fillit);
	}
}


