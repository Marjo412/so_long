/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:41:56 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/10 11:09:58 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
		if (write(1, "(null)", 6) == -1)
			return (-1);
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

/*function for print a string, return the nb of byte print. 
If the string is null : write (null) if write (null) failed return -1*/