/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:00 by tbouline          #+#    #+#             */
/*   Updated: 2016/12/01 22:22:09 by tbouline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_tetriminos
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_tetriminos;

#endif
