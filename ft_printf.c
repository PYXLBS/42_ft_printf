/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:28:40 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/09 13:47:05 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_handle_content(const char **content)
{
	int	len;

	len = 0;
	while (**content != '\0')
	{
		ft_putchar(**content);
		len++;
		(*content)++;
	}
	return (len);
}

int	ft_printf(const char *content, ...)
{
	va_list		args;
	const char	*perc;
	char		flag;
	int			len;

	len = 0;
	va_start(args, content);
	while (content != NULL && *content != '\0')
	{
		perc = ft_strchr(content, '%');
		if (content == perc)
		{
			flag = *(perc + 1);
			len = len + ft_convert(flag, args);
			content = content + 2;
		}
		else
			len = len + ft_handle_content(&content);
	}
	va_end(args);
	return (len);
}
