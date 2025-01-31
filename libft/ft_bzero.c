/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:13:13 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/12 14:30:29 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		dest[i] = 0;
		i++;
	}
}

/* Le but est de parcourir la zone memoire et de mettre 0 a chaque octet de 
cette zone sur une longueur donnee */
