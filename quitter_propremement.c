//TOUT FREE. MEME SI ERREUR TOUT DOIT ETRE FREE. 

//Perso quand j'ai trop de variables, j'utilise une structure. Tu peux ranger ta liste chainee et un pointeur *begin dedans, ainsi que plus ou moins tout. Comme ça un seul parametre a passer, et plus facile de tout free.

void	ft_freetout(t_fourretout *willayyy, int error)
{
	int		i;

	i = 0;
	if (willayyy)
	{	
		while (willayyy->begin)
		{
			willay->begin = willayy->list->next;
			free(willayy->list);
			willayy->list = NULL;
			willayy->list = willayy->begin;
			//un truc dans le genre quoi.
		}
		//... meme chose si tu as des tableaux a free par exemple.
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
	}
	exit(error); // echo $? sur le shell pour voir comment ça a quitté, gadget mais why not. Bonus cool pour minishell
}

ft_stop(t_fourretout *willayyy, int error) // envoyer zero en error si success.
{
	if (error == 1)
		ft_putendl_fd("Usage: ./fillit map", 2);
	else if (error == 2)
		ft_putendl_fd("invalid map");
	else if (error == 3)
		ft_putendl_fd("malloc error");
	ft_freetout(willayyy, error);
}

