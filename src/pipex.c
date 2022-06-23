/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:38:17 by krozis            #+#    #+#             */
/*   Updated: 2022/06/23 15:26:50 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_dup(int input, int output, t_px *px)
{
	if (dup2(input, STDIN) == -1)
		px_exit(px_msg(strerror(errno), "", "", EXIT_FAILURE), px);
	if (dup2(output, STDOUT) == -1)
		px_exit(px_msg(strerror(errno), "", "", EXIT_FAILURE), px);
}

static void	px_child(t_px *px)
{
	if (px->child == 0)
		px_dup(px->fd_in, px->pipe[1], px);
	else if (px->child == px->nb_cmd - 1)
		px_dup(px->pipe[2 * px->child - 2], px->fd_out, px);
	else
		px_dup(px->pipe[2 * px->child - 2], px->pipe[2 * px->child + 1], px);
	if (px->cmd == NULL || px->options == NULL)
		px_exit(EXIT_FAILURE, px);
	px_close(px);
	if (execve(px->cmd, px->options, px->envp) == -1)
		px_exit(px_msg(px->options[0], ": ", strerror(errno),
				EXIT_FAILURE), px);
}

static int	px_parent(t_px *px)
{
	pid_t	pid;
	int		status;
	int		exit_code;

	px_close(px);
	exit_code = 1;
	px->child--;
	while (px->child >= 0)
	{
		pid = waitpid(px->pids[px->child], &status, 0);
		if (pid == px->pids[px->nb_cmd - 1])
		{
			if ((px->child == (px->nb_cmd - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		px->child--;
	}
	free(px->pids);
	free(px->pipe);
	return (exit_code);
}

static int	pipex(t_px *px)
{
	px->child = 0;
	while (px->child < px->nb_cmd)
	{
		px->options = ft_split(px->av[px->child + 2], ' ');
		if (px->options == NULL)
			px_exit(px_msg("unexpected error", "", "", EXIT_FAILURE), px);
		px->cmd = px_get_cmd(px->options[0], px);
		px->pids[px->child] = fork();
		if (px->pids[px->child] == -1)
			px_exit(px_msg("fork", ": ", strerror(errno), 1), px);
		if (px->pids[px->child] == PID_CHILD)
			px_child(px);
		px_free(px->cmd, px->options);
		px->child++;
	}
	return (px_parent(px));
}

int	main(int ac, char **av, char **envp)
{
	t_px	px;

	if (ac < 5)
		return (px_msg("Usage: ./pipex INFILE cmd1 cmd2 ... cmdn OUTFILE",
				"", "", EXIT_FAILURE));
	px = px_init(ac, av, envp);
	return (pipex(&px));
}
