/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:28:12 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 13:24:30 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

size_t	ft_strlen( const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)(src + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(src + i));
	return (NULL);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(src);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		result[j] = s[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}*/

/* This file contain all functions needed fo the principal function.
/!\ Always check if the string is NULL
* Strjoin is for concate the buffer and the line in construction, it's easier
for allocate the memory.
* Strlen for calculate the lenght of the strig
* Strdup for the copy of the string with the allocation of the memory 
* Substr is for take off the substring in the buffer to the stash.
*Strchr is for search a '\n', if there is one, gnl use substr or if not
'read' continue to read and concate with strjoin.*/