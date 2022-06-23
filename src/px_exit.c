/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:51:55 by krozis            #+#    #+#             */
/*   Updated: 2022/06/23 15:43:46 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_free(char *str, char **tab)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (tab != NULL)
	{
		i = 0;
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	px_close(t_px *px)
{
	int	i;

	if (px->fd_in != -1)
		close(px->fd_in);
	if (px->fd_out != -1)
		close(px->fd_out);
	i = 0;
	while (i < (px->nb_cmd - 1) * 2)
	{
		close(px->pipe[i]);
		i++;
	}
}

int	px_msg(char *s1, char *s2, char *s3, int exit_code)
{
	ft_putstr_fd("pipex: ", STDERR);
	ft_putstr_fd(s1, STDERR);
	ft_putstr_fd(s2, STDERR);
	ft_putendl_fd(s3, STDERR);
	return (exit_code);
}

int	px_exit(int exit_code, t_px *px)
{
	if (px != NULL)
		px_close(px);
	if (px->pids != NULL)
	{
		free(px->pids);
		px->pids = NULL;
	}
	if (px->pipe != NULL)
	{
		free(px->pipe);
		px->pipe = NULL;
	}
	if (px->cmd != NULL)
		px_free (px->cmd, NULL);
	if (px->options != NULL)
		px_free(NULL, px->options);
	exit(exit_code);
}
