/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:24:22 by pabertha          #+#    #+#             */
/*   Updated: 2023/07/03 23:53:07 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	o;

	o = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n > o)
	{
		if (((unsigned char *)s1)[o] != ((unsigned char *)s2)[o])
			return (((unsigned char *)s1)[o] - ((unsigned char *)s2)[o]);
		o++;
	}
	return (0);
}
