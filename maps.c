/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:33 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 09:50:18 by mrosset          ###   ########.fr       */
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
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_window, map->player,
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

static int	print_map_error(char *message)
{
	ft_printf("Error : %s\n", message);
	return (0);
}

int	is_valid_map(t_game *game)
{
	if (!is_rectangle(game->map))
		return (print_map_error("map is not rectangle"));
	if (!is_valid_chars(game->map))
		return (print_map_error("map contains invalid chars"));
	if (!has_required_elements(game->map))
		return (print_map_error("must contain 1 P, 1 E and at least 1 C"));
	if (!check_walls(game->map))
		return (print_map_error("map must be surrounded by walls"));
	if (!is_path_valid(game))
		return (print_map_error("not all elements are reachable"));
	return (1);
}

/*
**render_tile : The function is called for each tile in the game
	map, which is then drawn on the screen. Renders a single tile (wall,
	floor, collectible, player, exit) into the game window.
**(tile) tuile ou unite de terrain (taille en pixel)
** read_map open and read a map's file and store content as a 2D array*/
