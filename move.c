/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:58:15 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/13 15:00:55 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectible--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collectible == 0)
	{
		ft_printf("Youpiii !! You win !!\n");
		exit_game(game);
		return ;
	}
	game->player_x = new_x;
	game->player_y = new_y;
	create_map(game);
}

/*
** the function move_player check the new posiion of the player, if its 1 (wall)
it don't move, if its C (collectible) replace a 0 (wall), if ita E (exit) and
the number of C is 0, htis this the end of the game.*/