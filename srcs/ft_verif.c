/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:01:42 by gduval            #+#    #+#             */
/*   Updated: 2016/11/28 17:24:29 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			check(char *buf, size_t i, size_t width, size_t height)
{
	size_t	count;

	count = 1;
	while (buf[i++] != '\0')
	{
		width++;
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
	return (count);
}

int			check_buf(char *buf)
{
	if (!buf)
		return (-1);
	return (check(buf, 0, 0, 0));
}