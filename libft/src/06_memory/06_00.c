/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:13:51 by stelie            #+#    #+#             */
/*   Updated: 2022/05/27 10:33:45 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*obj;

	obj = malloc(nmemb * size);
	if (obj == NULL)
		return (NULL);
	ft_bzero(obj, nmemb * size);
	return (obj);
}
