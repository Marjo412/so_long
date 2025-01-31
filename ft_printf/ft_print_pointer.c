/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:53:37 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/10 10:57:36 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_long(unsigned long n, char c)
{
	char	*base;
	int		count;

	count = 0;
	base = "0";
	if (c == 'X')
		base = HEXA_BASE_UPPER;
	else if (c == 'x')
		base = HEXA_BASE_LOWER;
	if (n >= 16)
		count += ft_print_hexa_long(n / 16, c);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = ft_print_string("0x");
	count += ft_print_hexa_long(address, 'x');
	return (count);
}

/* 0x : address prefix
use unsigned long to allow capturing the full address of the pointer.
line 26 : call the recursion to display the integer in hexadecimal*/