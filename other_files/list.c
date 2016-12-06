#include "list.h"
#include <stdlib.h>
#include <string.h>

int		main(int ac, char **av)
{
	t_level		*level;
	int			i;
	t_level		*begin;

	i = 1;	
	if (ac == 1)
		return (0);
	level = (t_level *)malloc(sizeof(t_level));
	level->prev = NULL;
	begin = level;
	while (av[i])
	{
		level->num = i;
		level->name = strdup(av[i]);
		if (i % 8 == 0)
			level->boss = 1;
		else
			level->boss = 0;
		level->time = i * 50;
		level->foes = i * 4;
		i++;
		if (av[i])
		{	
			level->next = (t_level *)malloc(sizeof(t_level));
			level->next->prev = level;
			level = level->next;
		}
	}
	level->next = NULL;
	level = begin;
	while (level != NULL)
	{
		printf("NUM %d NAME %s BOSS %u TIME %zu FOES %d\n", level->num, level->name, level->boss, level->time, level->foes);
		level = level->next;
	}
	level = begin;
	while (level)
	{
		begin = level->next;
		free(level->name);
		level->name = NULL;
		free(level);
		level = NULL;
		level = begin;
	}
}


// NE JAMAIS OUBLIER LES NULL.
// SI SIMPLE, STOCKER PREMIER MAILLON DANS UN BEGIN. POUR REVENIR AU DEBUT FAIRE LEVEL = BEGIN
// SI DOUBLE, INCLURE LIST->NEXT->PREV = LIST POUR POUVOIR STEPBACK
// SI CIRCULAIRE NE PAS TERMINER PAR NULL, "TERMINER" PAR BEGIN
// UNE LISTE PEUT ETRE CIRCULAIRE ET DOUBLE. LES POSSIBILITES SONT CELLES QUE TU VEUX
