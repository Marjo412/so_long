/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:23:48 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/12 14:39:26 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		dest[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*rempli une zone memoire avec une valeur donnee sur un certain nd d'octets,
utilisée pour initialiser des tableaux*/