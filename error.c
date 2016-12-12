/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:43:06 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/11 04:41:18 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				exit_fillit(t_fillit *fillit, int error)
{
	int		i;

	i = -1;
	if (fillit)
	{
		if (SOLVE_MAP)
			SOLVE_MAP = free_pointers(SOLVE_MAP);
		else if (MAP)
		{
			while (MAP[++i])
				MAP[i] = free_pointers(MAP[i]);
			MAP = NULL;
		}
		else if (BUF)
		{
			free(BUF);
			BUF = NULL;
		}
		free(fillit);
		fillit = NULL;
	}
	exit(error);
}

void					ft_error(t_fillit *fillit, int error)
{
	if (error == ARGUMENT)
		ft_putendl_fd("Usage: ./fillit [tetriminos source file]", 2);
	else if (error == ERROR)
		ft_putendl_fd("error", 2);
	exit_fillit(fillit, error);
}
