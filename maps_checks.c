/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:56 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/13 16:49:44 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int is_rectangle(char **map)
{
    int     i;
    size_t  len;

    if (!map || !map[0])
        return (0);
    len = ft_strlen(map[0]);
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != len)
            return(0);
        i++;
    }
    return (1);
}

int is_valid_chars(char **map)
{
    int i;
    int j;

    if (!map)
        return (0);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
                && map[i][j] != 'C' && map[i][j] != 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
