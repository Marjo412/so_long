/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:58:15 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/25 14:49:17 by mrosset          ###   ########.fr       */
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

static int	handle_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == 'E')
	{
		if (game->collectible_count == 0)
		{
			ft_printf("Youpiii !! You win !!\n");
			exit_game(game);
			return (0);
		}
		else
		{
			ft_printf("These are still collectibles!\n");
			return (0);
		}
	}
	if (tile == 'C')
	{
		game->collectible_count--;
		game->map[y][x] = '0';
	}
	return (1);
}

static void	update_position(t_game *game, int x, int y)
{
	if (!handle_tile(game, x, y))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	game->map[y][x] = 'P';
	game->move++;
	ft_printf("Moves : %d\n", game->move);
	create_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_width
		|| new_y < 0 || new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (!handle_tile(game, new_x, new_y))
		return ;
	if (game->map[new_y][new_x] != 'E')
		update_position(game, new_x, new_y);
}

/*
** the function move_player check the new posiion of the player, if its 1 (wall)
it don't move, if its C (collectible) replace a 0 (floor), if it's E (exit) and
the number of C is 0, this is the end of the game.*/