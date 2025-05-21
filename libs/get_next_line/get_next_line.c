/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:43:49 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 14:17:06 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stash(char *stash, char *buffer)
{
	char	*temp;

	if (!stash)
		return (gnl_ft_strdup(buffer));
	temp = stash;
	stash = gnl_ft_strjoin(stash, buffer);
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
	while (bytes_read > 0 && gnl_ft_strchr(stash, '\n') == NULL)
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
	previous_line = gnl_ft_strchr(*stash, '\n');
	if (previous_line != NULL)
	{
		line = gnl_ft_substr(*stash, 0, previous_line - *stash + 1);
		temp = gnl_ft_strdup(previous_line + 1);
		free(*stash);
		*stash = temp;
		if (line == NULL || *stash == NULL)
			return (NULL);
	}
	else
	{
		line = gnl_ft_strdup(*stash);
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
		stash = gnl_ft_strdup("");
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
