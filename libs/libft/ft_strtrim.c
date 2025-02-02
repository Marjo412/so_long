/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:25:20 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/24 10:41:50 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	first;
	size_t	last;
	char	*dest;

	first = 0;
	last = ft_strlen(s1);
	while (s1[first] != '\0' && ft_strchr(set, s1[first]) != NULL)
		first++;
	while (last > first && ft_strchr(set, s1[last - 1]) != NULL)
		last--;
	dest = (char *)malloc(sizeof(char) * ((last - first) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (first < last)
	{
		dest[i] = s1[first];
		i++;
		first++;
	}
	dest[i] = '\0';
	return (dest);
}
/*Permet d'enlever les carac. indésirables au début, à la fin de la chaîne.
s1: La chaîne de caractères à trimmer.
set: Le set de référence de caractères à trimmer*/
