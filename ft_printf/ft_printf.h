/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:05:56 by mrosset           #+#    #+#             */
/*   Updated: 2024/11/08 09:47:49 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h> /*write*/
# include <stdio.h> /*printf*/
# include <stdarg.h> /*va_list*/
# include <stdlib.h> /*malloc*/
# define HEXA_BASE_UPPER "0123456789ABCDEF"
# define HEXA_BASE_LOWER "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_decimal(int n);
int	ft_print_hexa(unsigned int n, char c);
int	ft_print_pointer(void *ptr);
int	ft_print_string(const char *str);
int	ft_print_unsigned(unsigned long n);

#endif
