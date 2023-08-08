/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:37:53 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/08 14:25:08 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putuint(unsigned int n)
{
	if (n >= 10)
		return (ft_putuint(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_puthex(unsigned int n, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		return (0);
	if (n >= 16)
		return (ft_puthex(n / 16, c) + ft_putchar(hex[n % 16]));
	else
		return (ft_putchar(hex[n]));
}

int	ft_putptr_hex(void *ptr)
{
	ft_putstr("0x");
	return (ft_puthex((unsigned int)(unsigned long)ptr, 'x') + 2);
}

int	ft_convert(char flag, va_list arg)
{
	int				print;
	unsigned long	addr;

	print = 0;
	if (flag == 'c' || flag == '%')
		print = ft_putchar(va_arg(arg, int));
	else if (flag == 's')
		print = ft_putstr(va_arg(arg, char *));
	else if (flag == 'p')
	{
		addr = (unsigned long)va_arg(arg, void *);
		print = ft_putptr_hex((void *)addr);
	}
	else if (flag == 'd' || flag == 'i')
		print = ft_putnbr(va_arg(arg, int));
	else if (flag == 'u')
		print = ft_putuint(va_arg(arg, unsigned int));
	else if (flag == 'x' || flag == 'X')
		print = ft_puthex(va_arg(arg, unsigned int), flag);
	return (print);
}
