/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:46:34 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/12 13:34:25 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_fillit			*ft_init(t_fillit *fillit)
{
	MAP = NULL;
	BUF = NULL;
	fillit->solve_map = NULL;
	if (!(fillit->buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
		ft_error(fillit, ERROR);
	fillit->line = 0;
	fillit->pieces = 0;
	fillit->fd = 0;
	fillit->height = 0;
	fillit->width = 0;
	fillit->faulty_piece = 0;
	fillit->square = 4;
	fillit->x = 0;
	fillit->y = 0;
	return (fillit);
}

static t_fillit			*openbuf(t_fillit *fillit, char *path)
{
	char	buf[BUF_SIZE + 1];
	int		ret;

	if ((fillit->fd = open(path, O_RDONLY)) == -1)
		ft_error(fillit, ERROR);
	if ((ret = read(fillit->fd, BUF, BUF_SIZE + 1)) == -1)
		ft_error(fillit, ERROR);
	buf[ret] = '\0';
	if (((fillit->pieces = checkbuf(fillit)) == -1) || ret >= 546)
		ft_error(fillit, ERROR);
	return (fillit);
}

int						main(int argc, char **argv)
{
	t_fillit	*fillit;

	fillit = NULL;
	if (!(fillit = (t_fillit *)malloc(sizeof(t_fillit))))
		ft_error(fillit, ERROR);
	fillit = ft_init(fillit);
	if (argc != 2)
		ft_error(fillit, ARGUMENT);
	fillit = openbuf(fillit, argv[1]);
	fillit = get_map(fillit);
	fillit = solver(fillit);
	//fillit = ft_display(fillit);
	return (0);
}
