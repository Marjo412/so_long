/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:53:34 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/10 11:15:43 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int n, char c)
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
		count += ft_print_hexa(n / 16, c);
	count += write(1, &base[n % 16], 1);
	return (count);
}

/*Function fo %x and %X
I define HEXA_BASE_UPPER and HEXA_BASE_LOWER in ft_printf.h
Change in base 16 for the hexadecimal*/