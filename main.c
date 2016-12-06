/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:46:34 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/06 06:33:38 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 546 //21 * 26 max

#include "includes/libft.h"
#include "fillit.h" 

int			openbuf(t_fillit *fillit, char *argv)
{
	if (!(fillit->fd = open(argv, O_RDONLY)))
		ft_error(fillit, OPEN);
	if (!(ret = read(fillit->fd, BUF, BUF_SIZE + 1)))
		ft_error(fillit, READ);
	if (ret > 546)
		ft_error(fillit, MAP ERROR);
	BUF[ret] = '\0';
	if ((checkbuf(BUF) == -1))
	{
		ft_error(fillit, TETRIMINOS);
	}
	return (fillit);
}

static t_fillit	*ft_init(t_fillit *fillit)
{
	fillit->pieces = 0;
	fillit->fd = 0;
	fillit->height = 0;
	fillit->width = 0;
	fillit->ret = 0;
	fillit->key = 0;
	fillit->faulty_piece = 0;
	fillit->map = NULL;
	fillit->buf = NULL;
	return (fillit):
}

t_fillit	ft_error(t_fillit *fillit, int error)
{
	if (error == 1)
		ft_putendl_fd("Usage: ./fillit [tetriminos source file]\n"), 2;
	else if (error == 2)
		ft_putendl_fd("open failed\n");
	else if (error == 3)
		ft_putendl_fd("read failed\n");
	else if (error == 4)
		ft_putendl_fd("malloc error\n");
	else if (error == 5)
		ft_putendl_fd("invalid tetrimino\n");
	else if (error == 6)
		ft_putendl_fd("invalid map \n");
	ft_freetout(fillit, error);
}

int			main(int argc, char **argv)
{
	t_fillit	*fillit;

	fillit = (t_fillit *)malloc(sizeof(t_fillit));
	if (argc != 2)
	{
		ft_error(fillit, ARGUMENT);
		fillit = ft_init(fillit);
		fillit = openbuf(fillit, argv[1]);
		fillit = ft_freetout(fillit);
		fillit = ft_verif(fillit);
		fillit = display(fillit);
		fillit = solver(fillit);
	}
}
