/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:29:30 by pabertha          #+#    #+#             */
/*   Updated: 2023/07/03 23:55:31 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		len = 0;
	else if (start + len > i)
		len = i - start;
	str = ft_calloc(len + 1, 1);
	if (str != NULL)
	{
		ft_memcpy(str, &s[start], len);
		str[len] = '\0';
	}
	return (str);
}
