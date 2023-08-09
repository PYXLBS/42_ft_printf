/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:17:08 by pabertha          #+#    #+#             */
/*   Updated: 2023/07/03 23:51:00 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	symb;
	int	res;

	i = 0;
	symb = 1;
	res = 0;
	while (nptr[i] != '\0')
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		if (nptr[i] == 43 || nptr[i] == 45)
		{
			if (nptr[i] == 45)
				symb = -symb;
			i++;
		}
		while (ft_isdigit(nptr[i]))
		{
			res = (res * 10) + (nptr[i] - 48);
			i++;
		}
		return (symb * res);
	}
	return (0);
}
