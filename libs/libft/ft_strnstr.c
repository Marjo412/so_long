/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:03:30 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/03 14:01:30 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (src[i + j] == str[j] && src[i + j] != '\0' && (i + j) < len)
		{
			if (str[j + 1] == '\0')
				return ((char *)&src[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/* src : string à comparer, str : string a chercher*/