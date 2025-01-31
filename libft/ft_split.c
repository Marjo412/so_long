/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:24:26 by mrosset           #+#    #+#             */
/*   Updated: 2025/01/21 10:44:47 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (*str)
	{
		if (*str != c && n == 0)
		{
			n = 1;
			i++;
		}
		else if (*str == c)
			n = 0;
		str++;
	}
	return (i);
}

static char	*ft_dup(const char *str, int start, int finish)
{
	char	*words;
	int		i;

	i = 0;
	words = malloc((finish - start + 1) * sizeof(char));
	if (words == NULL)
		return (NULL);
	while (start < finish)
		words[i++] = str[start++];
	words[i] = '\0';
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			index;
	char		**dest;

	dest = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			dest[j++] = ft_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}
/*s: La chaîne de caractères à découper. c: Le caractère délimiteur.
 Split permet de diviser une string en plusieurs sous-string, séparer par
 un caractère délimiteur. permet d'obetnir un tableau avec chaque segment
 */
