/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:05 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 15:50:34 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_game(t_game *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
	{
		perror("mlx_init failed");
		exit(EXIT_FAILURE);
	}
	if (game_init->map_width <= 0 || game_init->map_height <= 0)
	{
		perror("Invalid map size");
		exit(EXIT_FAILURE);
	}
	game_init->mlx_window = mlx_new_window(game_init->mlx_ptr,
			game_init->map_width * TILE_SIZE,
			game_init->map_height * TILE_SIZE, "so_long");
	if (game_init->mlx_window == NULL)
	{
		perror("mlx_new_window failed");
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_game *game)
{
	int	image_width;
	int	image_height;

	game->player = mlx_xpm_file_to_image(game->mlx_ptr, \
	"textures/player.xpm", &image_width, &image_height);
	game->collectible_texture = mlx_xpm_file_to_image(game->mlx_ptr, \
	"textures/collectible.xpm", &image_width, &image_height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, \
	"textures/exit.xpm", &image_width, &image_height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
	"textures/wall.xpm", &image_width, &image_height);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, \
	"textures/floor.xpm", &image_width, &image_height);
	if (!game->player || !game->collectible_texture || !game->exit
		|| !game->wall || !game->floor)
		perror("init_textures failed");
}

int	exit_game(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->collectible_texture)
		mlx_destroy_image(game->mlx_ptr, game->collectible_texture);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	free_map(game->map);
	exit(EXIT_SUCCESS);
	return (0);
}
