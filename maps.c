/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:58:33 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 08:59:42 by mrosset          ###   ########.fr       */
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

int	is_valid_map(t_game *game)
{
	if (!is_rectangle(game->map))
	{
		ft_printf("Error : map is not rectangle\n");
		return (0);
	}
	if (!is_valid_chars(game->map))
	{
		ft_printf("Error : map contain invalid chars\n");
		return (0);
	}
	if (!has_required_elements(game->map))
	{
		ft_printf("Error : must contain 1 P, 1 E and at least 1 C\n");
		return (0);
	}
	if (!check_walls(game->map))
	{
		ft_printf("Error : map must be surrounded by walls\n");
		return (0);
	}
	if (!is_path_valid(game))
	{
		ft_printf("Error : not all elements are reachable\n")
		return (0);
	}
	return (1);
}

/*
**render_tile : The function is called for each tile in the game
	map, which is then drawn on the screen. Renders a single tile (wall,
	floor, collectible, player, exit) into the game window.
**(tile) tuile ou unite de terrain (taille en pixel)
** read_map open and read a map's file and store content as a 2D array*/
