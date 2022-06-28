/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:36:46 by stelie            #+#    #+#             */
/*   Updated: 2022/06/28 14:01:39 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*px_get_full_path(char *cmd, char **env_tab)
{
	char	*full;
	char	*tmp;
	int		i;

	i = 0;
	while (env_tab[i] != NULL)
	{
		tmp = ft_strjoin("/", cmd);
		full = ft_strjoin(env_tab[i], tmp);
		if (tmp != NULL)
			free(tmp);
		if (access(full, F_OK | X_OK) == CAN_ACCESS)
			return (full);
		if (full != NULL)
			free(full);
		full = NULL;
		i++;
	}
	return (NULL);
}

static char	**px_env_tab(char **envp)
{
	char	**env_tab;
	int		i;

	env_tab = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_tab = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (env_tab);
}

char	*px_get_cmd(char *cmd, t_px *px)
{
	char	**env_tab;
	char	*full;

	env_tab = NULL;
	full = NULL;
	if (access(cmd, F_OK | X_OK) == CAN_ACCESS)
		return (ft_strdup(cmd));
	env_tab = px_env_tab(px->envp);
	if (env_tab == NULL)
		return (NULL);
	full = px_get_full_path(cmd, env_tab);
	px_free(NULL, env_tab);
	if (full == NULL)
		px_msg("command not found", ": ", px->av[px->child + 2], EXIT_FAILURE);
	return (full);
}
