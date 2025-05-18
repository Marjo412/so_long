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

//continuer ce fichier