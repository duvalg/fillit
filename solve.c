/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:15:27 by gduval            #+#    #+#             */
/*   Updated: 2016/12/12 13:31:28 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**init_map(t_fillit *fillit)
{
	int		i;

	i = 0;
	if (!(SOLVE_MAP = (char **)ft_memalloc(sizeof(char *) * SQUARE + 1)))
		return (NULL);
	while (i < SQUARE)
	{
		SOLVE_MAP[i] = (char *)ft_memalloc(sizeof(char) * (SQUARE + 1));
		ft_bzero(SOLVE_MAP[i], SQUARE + 1);
		ft_memset(SOLVE_MAP[i], '.', SQUARE);
		i++;
	}
	SOLVE_MAP[i] = NULL;
	return (SOLVE_MAP);
}

char			**clean_map(t_fillit *fillit, char letter) // REMPLACE TOUT LES CARACTERES LETTER PAR DES '.'
{
	int			line;
	int			col;

	line = 0;
	col = 0;
	while (SOLVE_MAP[line])
	{
		while (SOLVE_MAP[line][col])
		{
			if(SOLVE_MAP[line][col] == letter)
				SOLVE_MAP[line][col] = '.';
			col++;
		}
		col = 0;
		line++;
	}
	return (SOLVE_MAP)
}

int				found_index(char letter) // REPERE OU SE SITUE LE PREMIER CARACTERE LETTER DANS LA MAP, UTILE POUR REPRENDRE A PARTIR D'UN POINT PRECIS AVEC LE BACKTRACKING
{
	int			line;
	int			col;

	line = 0;
	col = 0;
	while (SOLVE_MAP[line])
	{
		while (SOLVE_MAP[line][col])
		{
			if(SOLVE_MAP[line][col] == letter)
				return ((line * SQUARE) + col);
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

char			**fill_map(t_fillit *fillit, char letter, int index) // A COMPLETER // ELLE PARCOURT LA SOLVE_MAP ET FAIT APPEL AUX DIFFERENTES FONCTIONS
{
	int			col;
	int			line;

	col = index % SQUARE;
	line = index / SQARE;
	if (!(SOLVE_MAP = init_map(fillit))
		ft_error(fillit, ERROR);
	while (SOLVE_MAP[line])
	{
		while (SOLVE_MAP[line][col])
		{
			if (place_tetri(fillit) == 1) // SI LE TETRIS A LA PLACE, ON PLACE LE TETRI ET RAPPELLE FILL_MAP, EN COMMENCEANT A L'INDEX 0 // IL FAUDRAIT QU'ON PUISSE SWITCHER DE TETRIMINOS A CE MOMENT LA
			{
				display_tetris();
				fill_map(fillit, letter + 1, 0);
			}
			if (SOLVE_MAP[line][col + 1] == '\0' && letter == 'A') // SI ON SE SITUE SUR LE \0 ET QUE LA LETTRE EST LE 'A', ALORS LE PREMIER TETRIMINOS N'A PAS LA PLACE. DU COUP, ON AGRANDIT LA MAP ET ON RECOMMENCE !
			{
				SQUARE += 1;
				fill_map(fillit, 'A');
			}
			else if (SOLVE_MAP[line][col + 1] == '\0' && letter != 'A') // SI LE TETRI N'A PAS LA PLACE, ON CLEAN LA MAP DE LA LETTRE PRECEDENTE ET ON RECOMMENCE A PARTIR DU CARACTERE SUIVANT LE PRECEDENT EMPLACEMENT DE LA PIECE (je sais, c'est pas clair...)
			{
				clean_map(fillit, letter - 1);
				fill_map(fillit, letter - 1, found_index(letter - 1) + 1); // Il faudrait que la fonction prenne un tetriminos en parametre plutot que tout fillit, pour qu'om puisse plus simplement naviguer entre les tetriminos
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (SOLVE_MAP); // POUET
}

/*
void			place_tetri(t_fillit *fillit)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fillit->pos[j][i] == '#')
				MAP[fillit->y + j][fillit->x + i];
			j++;
		}
		i++;
	}
}
*/

t_fillit	*solver(t_fillit *fillit)
{
	place_tetri(fillit); // LA FONCTION DU TURFU
	return (fillit);
}
