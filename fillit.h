/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:00 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/12 11:55:20 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

# define SUCCESS 0
# define ARGUMENT 1
# define ERROR 2

# define BUF_SIZE 1024

# define BUF fillit->buf
# define HEIGHT fillit->height
# define WIDTH fillit->width
# define MAP fillit->map
# define SOLVE_MAP fillit->solve_map
# define SQUARE fillit->square

typedef struct	s_fillit
{
	int			pieces;
	int			fd;
	int			height;
	int			width;
	size_t		faulty_piece;
	size_t		line;
	char		*buf;
	char		***map;
	char		**pos;
	char		**solve_map;
	int			square;
	int			x;
	int			y;
}				t_fillit;

void			ft_error(t_fillit *fillit, int error);
t_fillit		*get_map(t_fillit *fillit);
int				checkbuf(t_fillit *fillit);
t_fillit		*solver(t_fillit *fillit);

#endif
