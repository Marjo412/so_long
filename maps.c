/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:33 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/09 11:17:05 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	create_map(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			render_tile(map, x, y);
			x++;
		}
		y++;
	}
}

void	render_tile(t_game	*map, int x, int y)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_window, map->wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (map->map[y][x] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_window, map->floor,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (map->map[y][x] == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_ptr, map->player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (map->map[y][x] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_window,
			map->collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (map->map[y][x] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_window, map->exit,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	char	*temp_map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("read_map failed");
		exit(EXIT_FAILURE);
	}
	temp_map = NULL;
	while ((line = get_next_line(fd)))
	{
		temp_map = ft_strjoin(temp_map, line);
		free(line);
	}
	game->map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
}

/*
**render_tile : The function is called for each tile in the game
	map, which is then drawn on the screen. Renders a single tile (wall,
	floor, collectible, player, exit) into the game window.
**(tile) tuile ou unite de terrain (taille en pixel)
** read_map open and read a map's file and store content as a 2D array*/
