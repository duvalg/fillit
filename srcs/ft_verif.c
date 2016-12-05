/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:01:42 by gduval            #+#    #+#             */
/*   Updated: 2016/12/03 16:36:19 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	error_message(size_t n)
{
	ft_putstr("bad tetriminos [");
	ft_putnbr((int)n + 1);
	ft_putstr("]\n");
}

static int	is_valid(char *buf, size_t i)
{
	size_t	div;
	size_t	line;

	div = i / 21;
	if (buf)
	{
		line = (i - (div * 21)) / 5;
		if (line == 0)
		{
			if (buf[i + 1] == '#' || buf[i - 1] == '#' || buf[i + 5] == '#')
				return (0);
		}
		if (line == 3)
		{
			if (buf[i + 1] == '#' || buf[i - 1] == '#' || buf[i - 5] == '#')
				return (0);
		}
		if (line > 0 && line < 3)
		{
			if (buf[i + 1] == '#' || buf[i - 1] == '#' || buf[i + 5] == '#' || \
			buf[i - 5] == '#')
				return (0);
		}
	}
	return (-1);
}

static int	check_char(char *buf, size_t i, size_t key)
{
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			if (is_valid(buf, i) == - 1)
			{
				error_message(i / 21);
				return (-1);
			}
		}
		key = (buf[i] == '#') ? key + 1 : key;
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
		{
			if (key != 4)
			{
				error_message(i / 21);
				return (-1);
			}
			key = 0;
		}
		i++;
	}
	return (0);
}

static int	check(char *buf, size_t i, size_t width, size_t height)
{
	size_t	count;

	count = 1;
	while (buf[i++] != '\0')
	{
		width++;
		if (buf[i - 1] == '\n' && width != 5 && height != 4)
			return (-1);
		if (buf[i - 1] != '\n' && buf[i - 1] != '.' && buf[i - 1] != '#')
			return (-1);
		if (height == 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (-1);
			count++;
			height = 0;
			width = 0;
		}
		if (width == 5)
		{
			if (buf[i - 1] != '\n')
				return (-1);
			height++;
			width = 0;
		}
	}
	return (count > 26 || check_char(buf, 0, 0) != 0) ? -1 : count;
}

int			checkbuf(char *buf)
{
	if (!buf)
		return (-1);
	return (check(buf, 0, 0, 0));
}
