/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:04:44 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/27 10:45:50 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*read_file_content(int fd)
{
	char	*line;
	char	*file_content;
	char	*temp;

	file_content = ft_strdup("");
	if (!file_content)
		return (NULL);
	line = read_line(fd);
	if (!line)
	{
		perror("Error : map empty");
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		temp = file_content;
		file_content = ft_strjoin(file_content, line);
		free(temp);
		free(line);
		if (!file_content)
			return (NULL);
		line = read_line(fd);
	}
	return (file_content);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*file_content;

	fd = open_file(filename);
	file_content = read_file_content(fd);
	close(fd);
	if (!file_content)
	{
		perror("read_map: memory allocation failed");
		exit(EXIT_FAILURE);
	}
	game->map = fill_map(file_content);
	free(file_content);
}

int	has_ber_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r');
}

/*** read_file_content : read all the file line by line and keep one big
	string.
*/