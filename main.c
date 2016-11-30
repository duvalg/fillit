/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:32:36 by gduval            #+#    #+#             */
/*   Updated: 2016/11/28 17:14:30 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 4096

#include "includes/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //daw

int			lstcreate(char *buf, size_t len)
{
	t_list	*tetriminos;

	if (!(tetriminos = ft_memalloc(sizeof(t_list) * len)))
	{
		ft_putstr("lstcreate() doesn't allocate memory\n");
		return (-1);
	}
	lstinsert(buf, tetriminos, len);
	return (0);
}

int			openbuf(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr("error : open() failed\n");
		return (-1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if ((checkbuf(buf) == -1))
	{
		ft_putstr("error : invalid Tetriminos\n");
		return (-1);
	}
	lstcreate(buf, checkbuf(buf));
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : fillit [tetriminos source file]\n");
		return (-1);
	}
	openbuf(argv[1]);
	return (1);
}
