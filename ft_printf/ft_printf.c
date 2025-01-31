/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:44:48 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/08 10:22:31 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_converstion(va_list args, const char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_converstion(args, format[i]);
		}
		else
		{
			count += ft_print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
