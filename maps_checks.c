/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checks.c                                       :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:36:56 by mrosset           #+#    #+#             */
/*   Updated: 2025/05/21 09:29:53 by mrosset        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_rectangle(char **map)
{
	int		i;
	size_t	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_chars(char **map)
{
	int	i;
	int	j;

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

int	has_required_elements(char **map)
{
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	count_elements(map, counts);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
		return (0);
	return (1);
}

void	count_elements(char **map, int counts[3])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				counts[0]++;
			else if (map[i][j] == 'E')
				counts[1]++;
			else if (map[i][j] == 'C')
				counts[2]++;
			j++;
		}
		i++;
	}
}

int	check_walls(char **map)
{
	int	i;
	int	width;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 0;
	while (map[0][i])
		if (map[0][i++] != '1')
			return (0);
	i = 0;
	while (map[i + 1])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i] && map[i + 1])
		i++;
	while (--width >= 0)
		if (map[i][width] != '1')
			return (0);
	return (1);
}
/*
**has_required_elements and count_element are for check if there is 
    exactly 1 Player, 1 Exit and at least 1 collectible.
    counts[0] == Player; counts[1] == Exit; counts[2] == Collectible*/
