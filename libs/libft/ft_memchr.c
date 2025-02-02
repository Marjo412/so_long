/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:23:29 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/17 11:13:06 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		if (d[i] == (unsigned char) c)
			return ((void *)(d + i));
		i++;
	}
	return (NULL);
}

/* rechercher un char dans un bloc de mémoire, pacourt le segment de mémoire
et renvoie un ptr vers la 1ère occurence d'un char spécifié ou NULL si pas
trouvé*/