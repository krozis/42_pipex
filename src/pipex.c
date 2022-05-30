/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:56:41 by krozis            #+#    #+#             */
/*   Updated: 2022/05/29 19:11:02 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	*options[] = { "sh", "./test.sh", NULL};
	
	if (ac != 2)
		return (ft_put_errmsg("Pas d'arg dans main.\n"));
	while (*envp)
	{
		ft_printf("%s\n", *envp);
		envp++;
	}
	ft_printf("Main Program Started:\n");
	execve(av[1], options, envp);
    perror("Could not execve");
  return 0;
}