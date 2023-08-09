/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:28:40 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/09 12:32:18 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_handle_content(const char **content, const char *perc)
{
	int	len;

	len = 0;
	while (**content != '\0' && *content != perc)
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
			len = len + ft_handle_content(&content, perc);
	}
	va_end(args);
	return (len);
}
