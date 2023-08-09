/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:28:40 by pabertha          #+#    #+#             */
/*   Updated: 2023/08/09 11:14:57 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		if (perc == content)
		{
			flag = *(content + 1);
			if (flag == '\0')
				break ;
			else
			{
				len = len + ft_convert(flag, args);
				content = content + 2;
			}
		}
		else
		{
			ft_putchar(*content);
			len++;
			content++;
		}
	}
	va_end(args);
	return (len);
}
