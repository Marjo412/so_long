/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:24:33 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/17 11:16:45 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&src[i]);
	return (NULL);
}

/* recherche la 1ere occurence d'un char donné dans une string*/