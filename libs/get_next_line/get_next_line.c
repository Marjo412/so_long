/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:28:08 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 13:59:59 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stash(char *stash, char *buffer)
{
	char	*temp;

	if (!stash)
		return (ft_strdup(buffer));
	temp = stash;
	stash = ft_strjoin(stash, buffer);
	if (!stash)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (stash);
}

static char	*free_stash(char *stash, char *buffer)
{
	if (stash)
		free(stash);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*read_and_clean_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			stash = free_stash (stash, buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = update_stash(stash, buffer);
		if (!stash)
			return (free_stash(stash, buffer));
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*temp;
	char	*previous_line;

	if (*stash == NULL || **stash == '\0')
		return (NULL);
	previous_line = ft_strchr(*stash, '\n');
	if (previous_line != NULL)
	{
		line = ft_substr(*stash, 0, previous_line - *stash + 1);
		temp = ft_strdup(previous_line + 1);
		free(*stash);
		*stash = temp;
		if (line == NULL || *stash == NULL)
			return (NULL);
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
			return (NULL);
	}
	stash = read_and_clean_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	return (line);
}

/*#include <stdio.h>
int main(void)
{
	while (1)
	{
		char	*line = get_next_line(0);
		if (!line)
			return (0);
		printf("%s\n", line);
		free(line);
	}

}*/

/*
-The function must read every line of the file with a nb of byte given.
-Return the nb oy bytes read, 0 if this is the end and -1 if error.
-The line read must evey time finish by the '/n'.
-The fd can be only major than 0, and the buffer is also more than 0, this is
why I check first those conditions.

*update_stash is for concate(ft_strjoin) the buffer to the stash and free the
buffer for the next line.

*free_stash is use for free the memory oh the stash and buffer

*extract_line is use for search the '\n' and pass the substring in the line,
if the '\n' is not found all the stash is return.
**line = ft_substr(stash(reserve), 0(depuis le debut de la stash), 
previous_line(pointe sur le '\n') - stash + 1(on inclut le '\n' de fin)); =
this code can take the beginig of the line to the '\n' n the stash and copy it

*read_and_clean_stash read the text until the '\n', pass the substring with
extract_line and free momory of the stash but keep what is after the '\n'.
*/