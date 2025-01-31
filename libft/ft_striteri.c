/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:24:48 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/24 10:14:11 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*Applique la fonction ’f’ à chaque caractère de la chaîne de caractères
transmise comme argument, et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à ’f’ afin d’être modifié si 
nécessaire.*/