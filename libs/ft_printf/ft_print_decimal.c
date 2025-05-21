/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:53:30 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 14:18:21 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;

	if (n == -2147483648)
		return (prf_ft_strdup("-2147483648"));
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

int	ft_print_decimal(int n)
{
	char	*s;
	int		count;

	s = ft_itoa(n);
	count = ft_print_string(s);
	free(s);
	s = NULL;
	return (count);
}

/*Functions for %d and %i
With itoa change an integer in a string
I didn't unse my libft for practice the function itoa*/