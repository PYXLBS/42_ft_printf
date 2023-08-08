/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:36 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/08 15:36:00 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	if (*s != '\0')
	{
		return (write (1, s, ft_strlen(s)));
	}
	return (0);
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
			n = -n;
			return (1 + ft_putnbr(n));
		}
		if (n >= 10)
			return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
		return (ft_putchar(n + '0'));
	}
	return (0);
}
