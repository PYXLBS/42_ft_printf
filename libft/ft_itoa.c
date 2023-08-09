/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:29:09 by pabertha          #+#    #+#             */
/*   Updated: 2023/07/03 23:51:45 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	len;

	len = 1;
	while (n > 9 || n < -9)
	{
		len++;
		n = n / 10;
	}
	if (n < 0)
		len++;
	return (len);
}

static char	*secure_int_min(void)
{
	char	*res;

	res = ft_calloc(12, 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

static char	*allocate_memory(int len)
{
	char	*res;

	res = ft_calloc(len + 1, 1);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	return (res);
}

static void	convert_int_to_char(int n, char *res, int len)
{
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (len > 0)
	{
		len--;
		if (len != 0 || res[0] != '-')
			res[len] = (n % 10) + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = get_length(n);
	if (n == INT_MIN)
		return (secure_int_min());
	res = allocate_memory(len);
	if (res == NULL)
		return (NULL);
	convert_int_to_char(n, res, len);
	return (res);
}
