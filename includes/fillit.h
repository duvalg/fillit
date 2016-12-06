/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:00 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/06 11:53:41 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define SUCCESS 0
# define ARGUMENT 1
# define OPEN 2
# define READ 3
# define MALLOC 4
# define TETRIMINOS 5
# define MAP_ERROR 6

# define BUF fillit->buf
# define HEIGHT fillit->height
# define WIDTH fillit->width
# define MAP fillit->map

typedef struct	s_fillit
{
	int			pieces;
	int			fd;
	int			height;
	int			width;
	int			ret;
	size_t		key;
	size_t		faulty_piece;
	char		*buf;
	char		***map;
}				t_fillit;

int				checkbuf(t_fillit *fillit);
t_fillit		free_map(t_fillit *fillit);
t_fillit		ft_free_tetris(t_fillit *fillit);
t_fillit		ft_new_map(t_fillit *fillit);

#endif
