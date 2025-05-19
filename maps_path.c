/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:47:07 by marvin            #+#    #+#             */
/*   Updated: 2025/05/18 17:47:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char    **copy_map(char **map)
{
    char    **copy;
    int     i;

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
            return(NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void    flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    if (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E' &&
        map[y][x] != 'P')
        return;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

int is_path_valid(t_game *game)
{
    char    **copy;

    copy = copy_map(map);
    if (!copy)
    {
        perror("Duplicate map failled");
        return (0);
    }
    flood_fill(copy, game->player_x, game->player_y);
    if (!check_reachable(copy))
    {
        free_map(copy);
        return (0);
    }
    free_map(copy);
    return (1);
}

int check_reachable(char **map)
{
    int x;
    int y;

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
//continuer ce fichier