/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:23:18 by mrosset           #+#    #+#             */
/*   Updated: 2024/10/25 12:53:27 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_n_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_n_len(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		dest[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}

/*converti un entier(int) en chaine de caracteres(char *)*/
