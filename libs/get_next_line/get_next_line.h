/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:28:04 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 14:15:43 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /*write, read*/
# include <stdlib.h> /*malloc*/
# include <stdio.h> /*printf*/
# include <fcntl.h> /*open*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	gnl_ft_len( const char *str);
char	*gnl_ft_strchr(const char *src, int c);
char	*gnl_ft_strdup(char *src);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);
#endif