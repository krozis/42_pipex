/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:23:22 by stelie            #+#    #+#             */
/*   Updated: 2022/05/27 10:33:45 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_base_to_int_dec(char *base, char *bnbr)
{
	int		nbr;
	int		mult;
	size_t	i;
	size_t	baselen;

	nbr = 0;
	mult = 0;
	i = ft_strlen(bnbr);
	baselen = ft_strlen(base);
	while (i > 0)
	{
		i--;
		nbr = nbr + (get_value(base, bnbr[i]) * (ft_power(mult, baselen)));
		mult++;
	}
	return (nbr);
}
