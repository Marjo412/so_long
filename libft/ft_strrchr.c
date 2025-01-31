/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:25:14 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/17 11:19:31 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	len;

	len = ft_strlen(src);
	if ((char)c == '\0')
		return ((char *)&src[len]);
	while (len > 0)
	{
		if (src[len - 1] == (char)c)
			return ((char *)&src[len - 1]);
		len--;
	}
	return (0);
}

/* recherche la dernière occurence d'un char donné dans une string*/