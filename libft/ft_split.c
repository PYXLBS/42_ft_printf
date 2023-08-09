/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:22:17 by pabertha          #+#    #+#             */
/*   Updated: 2023/07/03 23:54:06 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_elements(char const *s, char c)
{
	int	i;

	i = 0;
	while (s != NULL && *s != '\0')
	{
		while (s != NULL && *s == c)
			s++;
		if (s != NULL && *s != '\0')
			i++;
		while (s != NULL && *s != '\0' && *s != c)
			s++;
	}
	return (i);
}

static char	*get_next_element(const char **s, char c)
{
	int		len;
	char	*target;

	while (*s != NULL && **s == c)
		(*s)++;
	target = ft_strchr(*s, c);
	if (target != NULL)
		len = target - *s;
	else
		len = ft_strlen(*s);
	return (ft_substr(*s, 0, len));
}

static void	free_elements(char **elements, int count)
{
	int	i;

	i = 0;
	while (elements != NULL && i < count)
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**elements;

	i = 0;
	count = count_elements(s, c);
	elements = (char **)ft_calloc(8 * (count + 1), 1);
	if (elements == NULL)
		return (NULL);
	while (i < count)
	{
		elements[i] = get_next_element(&s, c);
		if (elements[i] == NULL)
		{
			free_elements(elements, i);
			return (NULL);
		}
		s = s + ft_strlen(elements[i]);
		i++;
	}
	elements[i] = NULL;
	return (elements);
}
