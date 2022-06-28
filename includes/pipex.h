/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:55:38 by stelie            #+#    #+#             */
/*   Updated: 2022/06/28 14:01:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define INFILE 0
# define OUTFILE 1
# define PID_CHILD 0
# define CAN_ACCESS 0
# define ERR_ACCESS -1

typedef struct s_px
{
	int		ac;
	char	**av;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		nb_cmd;
	int		child;
	int		*pids;
	int		*pipe;
	char	*cmd;
	char	**options;
}				t_px;

/*
	FUNCTIONS : init
*/
t_px	px_init(int ac, char **av, char **envp);

/*
	FUNCTIONS : exit
*/
void	px_free(char *str, char **tab);
void	px_close(t_px *px);
int		px_msg(char *s1, char *s2, char *s3, int exit_code);
int		px_exit(int exit_code, t_px *px);

/*
	FUNCTIONS: envp
*/
char	*px_get_cmd(char *cmd, t_px *px);

#endif