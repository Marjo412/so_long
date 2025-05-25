/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:36:28 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/25 09:51:38 by mrosset          ###   ########.fr       */
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

void	init_map_info(t_game *game)
{
	int	x;
	int	y;

	game->map_height = 0;
	game->collectible_count = 0;
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
			}
			else if (game->map[y][x] == 'C')
				game->collectible_count++;
			x++;
		}
		y++;
	}
}
