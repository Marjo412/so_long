/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:54 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/24 09:57:03 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t len)
{
	void	*dest;

	dest = (void *)malloc(nb * len);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, (nb * len));
	return (dest);
}

/*alloue dynamiquement de la mémoire pour un certain nb d'objet d'un certaine
len, en initialisant la mémoire allouée à 0. Renvoie un ptr vers le bloc de
mémoire allouée*/
