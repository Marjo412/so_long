/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:50:10 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/27 10:44:55 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!has_ber_extension(argv[1]))
		{
			ft_printf("Error: map must have a .ber extension\n");
			return (1);
		}
		read_map(&game, argv[1]);
		init_map_info(&game);
		if (!is_valid_map(&game))
		{
			free_map(game.map);
			exit(EXIT_FAILURE);
		}
		init_game(&game);
		init_textures(&game);
		create_map(&game);
		mlx_key_hook(game.mlx_window, handle_keypress, &game);
		mlx_hook(game.mlx_window, 17, 0, exit_game, &game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_printf("Error, it must have 2 args!\n");
	return (0);
}

/*17 is the code for close the window*/