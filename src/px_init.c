/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:44:41 by stelie            #+#    #+#             */
/*   Updated: 2022/06/28 14:01:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	px_make_pipes(t_px *px)
{
	int	i;

	i = 0;
	while (i < px->nb_cmd - 1)
	{
		if (pipe(px->pipe + (2 * i)) == -1)
			px_exit(px_msg("pipe", strerror(errno), "", EXIT_FAILURE), px);
		i++;
	}
}

static void	px_get_in_out(t_px *px)
{
	px->fd_in = open(px->av[1], O_RDONLY);
	if (px->fd_in == -1)
		px_exit(px_msg(strerror(errno), ":", px->av[1], 1), px);
	px->fd_out = open(px->av[px->ac - 1], O_CREAT | O_WRONLY | O_TRUNC,
			S_IROTH | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if (px->fd_out == -1)
		px_exit(px_msg(strerror(errno), ":", px->av[px->ac - 1], 1), px);
}

static t_px	px_init_null(void)
{
	t_px	px;

	px.ac = -1;
	px.av = NULL;
	px.envp = NULL;
	px.fd_in = -1;
	px.fd_out = -1;
	px.nb_cmd = -1;
	px.child = -1;
	px.pids = NULL;
	px.pipe = NULL;
	px.cmd = NULL;
	px.options = NULL;
	return (px);
}

t_px	px_init(int ac, char **av, char **envp)
{
	t_px	px;

	px = px_init_null();
	px.ac = ac;
	px.av = av;
	px.envp = envp;
	px_get_in_out(&px);
	px.nb_cmd = px.ac - 3;
	px.pids = malloc(sizeof(int) * px.nb_cmd);
	if (px.pids == NULL)
		px_exit(px_msg("PID error", strerror(errno), "", EXIT_FAILURE), &px);
	px.pipe = malloc(sizeof(int) * ((px.nb_cmd - 1) * 2));
	if (px.pipe == NULL)
		px_exit(px_msg("Pipe error", "", "", EXIT_FAILURE), &px);
	px_make_pipes(&px);
	return (px);
}
