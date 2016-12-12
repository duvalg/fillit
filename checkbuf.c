/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:49:08 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/12 11:22:52 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_pos(t_fillit *fillit, int i)
{
	int		end;
	int		links;

	end = i;
	links = 0;
	while (BUF[end])
	{
		if (BUF[end] == '\n' && (BUF[end + 1] == '\n' || BUF[end + 1] == '\0'))
			break ;
		end++;
	}
	while (i < end)
	{
		if (BUF[i] == '#')
		{
			if (links == 3 || links == 4)
				return (0);
			if (BUF[i + 1] == '#')
				links++;
			if (i + 5 < end && BUF[i + 5] == '#')
				links++;
		}
		i++;
	}
	return (-1);
}

static int		check_char(t_fillit *fillit, size_t i)
{
	int		key;

	key = 0;
	while (BUF[i] != '\0')
	{
		key = (BUF[i] == '#') ? key + 1 : key;
		if (BUF[i] == '#' && key == 1)
			if (check_pos(fillit, i) == -1)
				return (-1);
		if (BUF[i] == '\n' && (BUF[i + 1] == '\n' || BUF[i + 1] == '\0'))
		{
			if (key != 4)
				return (-1);
			key = 0;
			fillit->line = 0;
		}
		else if (BUF[i] == '\n' && BUF[i - 1] != '\n')
			fillit->line++;
		i++;
	}
	return (0);
}

static int		check(t_fillit *fillit, size_t i, size_t count)
{
	while (BUF[i++])
	{
		WIDTH++;
		fillit->faulty_piece = i / 21;
		if (BUF[i - 1] != '\n' && BUF[i - 1] != '.' && BUF[i - 1] != '#')
			ft_error(fillit, ERROR);
		if (BUF[i - 1] == '\n' && WIDTH != 5 && HEIGHT != 4)
			ft_error(fillit, ERROR);
		if (HEIGHT == 4)
		{
			if (BUF[i] != '.' && BUF[i] != '#')
				ft_error(fillit, ERROR);
			count++;
			HEIGHT = 0;
			WIDTH = 0;
		}
		if (WIDTH == 5)
		{
			if (BUF[i - 1] != '\n')
				ft_error(fillit, ERROR);
			HEIGHT++;
			WIDTH = 0;
		}
	}
	return ((count > 26 || check_char(fillit, 0) != 0) ? -1 : count);
}

int				checkbuf(t_fillit *fillit)
{
	if (!BUF)
		ft_error(fillit, ERROR);
	return (check(fillit, 0, 1));
}
