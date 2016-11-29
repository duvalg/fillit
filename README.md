# fillit

Résumé: c’est l’histoire d’une pièce de Tetris, d’un petit carré et d’un(e)
codeur/codeuse qui entrent dans un bar...


Fillit ne consiste pas à recoder Tetris, mais reste une variante du jeu dans l’esprit.
Votre programme prendra en paramètre un fichier décrivant une liste de Tetriminos
qu’il devra ensuite agencer entre eux pour former le plus petit carré possible. Le but est
bien entendu de trouver ce plus petit carré le plus rapidement possible malgré un nombre
d’agencements qui croît de manière explosive avec chaque pièce supplémentaire.


// Entrée du programme

Votre exécutable doit prendre en paramètre un (et un seul) fichier décrivant la liste
des Tetriminos à agencer. Ce fichier est formaté de façon très précise : chaque description
d’un Tetriminos est sur 4 lignes et deux Tetriminos sont séparés par une ligne vide.
Si le nombre de paramètres passés à votre executable est différent de 1, votre programme
doit afficher son usage et quitter proprement. Si vous ingorez ce qu’est un usage,
lancez la commande cp sans argument dans votre shell pour vous faire une idee.
La description d’un Tetriminos doit respecter les règles suivantes :
• Exactement 4 lignes de 4 caractères suivis d’un retour à la ligne.
• Un Tetriminos est une pièce de Tetris classique composée de 4 blocs.
• Chaque caractère doit être, soit un ’#’ lorsque la case correspond à l’un des 4
blocs d’un Tetriminos, soit un ’.’ lorsque la case est vide.
• Chaque bloc d’un Tetriminos doit être en contact avec au moins un autre bloc
sur l’un ou l’autre de ses 4 côtés.


// Le plus petit carré

Le but de ce projet est d’agencer les Tetriminos entre eux pour former le plus petit
carré possible, sachant que ce carré peut présenter des trous quand les pièces données ne
s’emboîtent pas parfaitement.
Chaque Tetriminos, bien que présenté sur une grille de 16 cases, n’est défini que
par ses cases pleines (ses ’#’). Les 12 ’.’ restants sont ignorés pour l’agencement des
Tetriminos entre eux.
Les Tetriminos sont placés dans l’ordre dans lequel ils apparaissent dans le fichier.
Parmi les différentes solutions possibles réalisant le plus petit carré, sera retenue la solution
où chaque Tetriminos est disposé le plus en haut, puis le plus à gauche possible, au
moment de son placement.


--
Fillit
Can you feel it ?
Team pedago pedago@staff.42.fr
