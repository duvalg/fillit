#ifndef LIST_H
# define LIST_H

# include <stdio.h>

typedef struct					s_level
{
	int					num;
	char				*name;
	unsigned int		boss:1;
	size_t				time;
	short int			foes;
	struct s_level		*next;
	struct s_level		*prev;
}								t_level;

