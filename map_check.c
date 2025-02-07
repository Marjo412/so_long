/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:20:04 by mrosset           #+#    #+#             */
/*   Updated: 2025/02/07 13:27:57 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void  create_map(t_game *game)
{
}

void  read_map(t_game *game, const char *filename)
{
  open();
  get_next_line();
}

void  free_map(char **map)
{
  int   i;

  if (map == NULL)
    exit(0);
  i = 0;
  while (map[i] != NULL)
  {
    free(map[i]);
    i++;
  }
  free(map);
}
