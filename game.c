/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:42:05 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/07 15:44:54 by mrosset          ###   ########.fr       */
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
		
	game_init->
}

void	init_textures(t_game *game)
{
	int	image_width;
	int	image_height;

	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
	"texture/player.xpm", &image_width, &image_height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, \
	"texture/collectible.xpm", &image_width, &image_height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
	"texture/exit.xpm", &image_width, &image_height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"texture/wall.xpm", &image_width, &image_height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, \
	"texture/floor.xpm", &image_width, &image_height);
	if (!game->textures.player || !game->textures.collectible
		|| !game->textures.exit || !game->textures.wall
		|| !game->textures.floor)
		perror("init_textures failed");
}

int	exit_game(t_game *game)
{
	mlx_destroy_window();
	free_map();
	exit(0);
	return (0);
}