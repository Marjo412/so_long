/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:04:44 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 10:11:27 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char *read_file_content(int fd)
{
    char    *line;
    char    *file_content;
    char    *temp;

    file_content = ft_strdup("");
    if (!file_content)
        return (NULL);
	line = read_line(fd);
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
