/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   00_03.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: stelie <stelie@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/17 18:09:05 by stelie			#+#	#+#			 */
/*   Updated: 2022/05/17 18:15:01 by stelie		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_hasdouble(int tab[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] == tab[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool	ft_issorted(int tab[], int len, t_bool increasing)
{
	int	i;

	i = 1;
	if (len <= 1)
		return (TRUE);
	while (i < len)
	{
		if (increasing)
		{
			if (tab[i - 1] > tab[i])
				return (FALSE);
		}
		if (!increasing)
		{
			if (tab[i - 1] < tab[i])
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
