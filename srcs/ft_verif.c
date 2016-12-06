/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:49:08 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/06 15:57:50 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_valid(t_fillit *fillit, size_t i)
{
	size_t	div;
	size_t	line;

	div = i / 21;
	if (BUF)
	{
		line = (i - (div * 21)) / 5;
		if (line == 0)
		{
			if (BUF[i + 1] == '#' || BUF[i - 1] == '#' || BUF[i + 5] == '#')
				return (0);
		}
		if (line == 3)
		{
			if (BUF[i + 1] == '#' || BUF[i - 1] == '#' || BUF[i - 5] == '#')
				return (0);
		}
		if (line > 0 && line < 3)
		{
			if (BUF[i + 1] == '#' || BUF[i - 1] == '#' || BUF[i + 5] == '#' || \
					BUF[i - 5] == '#')
				return (0);
		}
	}
	return (-1);
}

static int	check_char(t_fillit *fillit, size_t i)
{
	int		key;

	key = 0;
	while (BUF[i] != '\0')
	{
		fillit->faulty_piece = i / 21;
		if (BUF[i] == '#')
		{
			if (is_valid(fillit, i) == -1)
				return (i / 21); // retourne le num de la piece erronee
		}
		key = (BUF[i] == '#') ? key + 1 : key;
		if (BUF[i] == '\n' && (BUF[i + 1] == '\n' || BUF[i + 1] == '\0'))
		{
			if (key != 4)
				return (i / 21);
			key = 0;
		}
		i++;
	}
	return (0);
}

static int	check(t_fillit *fillit, size_t i)
{
	size_t	count;

	count = 1;
	while (BUF[i++])
	{
		WIDTH++;
		if (BUF[i - 1] == '\n' && WIDTH != 5 && HEIGHT != 4)
			return (i / 21);
		if (BUF[i - 1] != '\n' && BUF[i - 1] != '.' && BUF[i - 1] != '#')
			return (i / 21);
		if (HEIGHT == 4)
		{
			if (BUF[i] != '.' && BUF[i] != '#')
				return (i / 21);
			count++;
			HEIGHT = 0;
			WIDTH = 0;
		}
		if (WIDTH == 5)
		{
			if (BUF[i - 1] != '\n')
				return (i / 21);
			HEIGHT++;
			WIDTH = 0;
		}
	}
	return ((count > 26 || check_char(fillit, 0) != 0) ? -1 : count);
}

int			checkbuf(t_fillit *fillit)
{
	if (!BUF)
		return (-1);
	return (check(fillit, 0));
}
