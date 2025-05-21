/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:36:28 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 09:16:36 by mrosset        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open_file failed");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char	*read_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

char	**fill_map(char *file_content)
{
	char	**map;

	map = ft_split(file_content, '\n');
	if (!map)
	{
		perror("fill_map failed");
		exit(EXIT_FAILURE);
	}
	return (map);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*file_content;
	char	*temp;

	fd = open_file(filename);
	file_content = ft_strdup("");
	line = read_line(fd);
	while (line)
	{
		temp = file_content;
		file_content = ft_strjoin(file_content, line);
		free(temp);
		free(line);
		if (!file_content)
		{
			perror("read_map: memory allocation failed");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	game->map = fill_map(file_content);
	free(file_content);
}

void	init_map_info(t_game *game)
{
	int	x;
	int	y;

	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
