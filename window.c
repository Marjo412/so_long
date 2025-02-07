/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:36:22 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/07 13:31:56 by mrosset          ###   ########.fr       */
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

/*
**void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
** width = largeur / height = hauteur*/