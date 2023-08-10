/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:36 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/10 10:12:44 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	return (write (1, s, ft_strlen(s)));
}

int	ft_putnbr(int n)
{
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			return (1 + ft_putnbr(-n));
		}
		if (n >= 10)
			return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
		return (ft_putchar(n + '0'));
	}
}
