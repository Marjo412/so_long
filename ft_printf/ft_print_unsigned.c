/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:53:41 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/10 11:08:25 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_un_len(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*unsigned_itoa(unsigned long n)
{
	char	*dest;
	size_t	len;

	len = ft_un_len(n);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	if (n == 0)
		dest[0] = '0';
	while (n != 0)
	{
		dest[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}

int	ft_print_unsigned(unsigned long n)
{
	char			*s;
	unsigned long	count;

	s = unsigned_itoa(n);
	if (s == NULL)
		return (0);
	count = ft_print_string(s);
	free(s);
	s = NULL;
	return (count);
}

/*functions made for %u
with unsigned_itoa change an unsigned int in a string */