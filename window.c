/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:36:22 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/02 16:40:23 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	open_window(t_game *game)
{
	mlx_new_window
}

int exit_window(t_game game)
{
	mlx_destroy_window(game);
	exit(0);
	return (0);
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
}

/*
**void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
** width = largeur / height = hauteur*/