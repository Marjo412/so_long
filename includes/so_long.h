/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:50:42 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/09 10:51:34 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/minilibx-linux/mlx.h"
# include "libs/get_next_line/get_next_line.h"

# define TILE_SIZE 64

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65364
# define KEY_DOWN 65361
# define KEY_RIGHT 65363
# define ESC 65387

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_window;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		move;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*floor;
}	t_game;

void	init_game(t_game *game_init);
void	init_textures(t_game *game);
void	create_map(t_game *map);
void	render_tile(t_game	*map, int x, int y);
void	free_map(char **map);
void	read_map(t_game *game, char *filename);
void	move_player(t_game *game, int dx, int dy);
int		exit_game(t_game *game);
int		handle_keypress(int keycode, t_game *game);

#endif