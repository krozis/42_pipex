# 42_pipex

| Nom du programme | pipex  |
|--|--|
| Fichiers de rendu | Makefile, *.h, *.c |
| Makefile | NAME, all, clean, fclean, re |
| Arguments | file1 cmd1 cmd2 file2 |
| Fonctions externes autorisées | open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid  ft_printf et tout équivalent que VOUS avez codé |
| Libft autorisée | Oui |
|  Description | Ce projet consiste à gérer des pipes. |



Votre programme sera exécuté comme suit : 

    ./pipex file1 cmd1 cmd2 file2 

Il doit prendre 4 arguments : 
- file1 et file2 sont des noms de fichier.
-  cmd1 et cmd2 sont des commandes shell avec leurs paramètres. 

Votre programme doit se comporter exactement comme la commande shell suivante : 

    $> < file1 cmd1 | cmd2 > file2 4
