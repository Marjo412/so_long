/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 10:40:29 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'F')
		return ;
	if (game->map[y][x] == 'E')
	{
		game->map[y][x] = 'F';
		return ;
	}
	if (game->map[y][x] != '0' && game->map[y][x] != 'C'
		&& game->map[y][x] != 'E' && game->map[y][x] != 'P')
		return ;
	game->map[y][x] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int	is_path_valid(t_game *game)
{
	int		reachable;
	char	**copy;
	char	**old_map;

	copy = copy_map(game->map);
	if (!copy)
	{
		perror("Duplicate map failled");
		return (0);
	}
	old_map = game->map;
	game->map = copy;
	flood_fill(game, game->player_x, game->player_y);
	reachable = check_reachable(copy);
	game->map = old_map;
	free_map(copy);
	return (reachable);
}

int	check_reachable(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/***copy_map : create a copy of the ma to do the flood.
**flood_fill : is for check if all elements are reachable from the
	player position, simulate a flood to mark accessible tiles.
** is_path_valid : check if the map is playable, create a copy of
	the original map, check with the flood and restore the map.
** check_reachable : check if collectibles and exit are reachable
	with the flood.
 */
