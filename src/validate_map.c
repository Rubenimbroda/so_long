/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:32:59 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 18:06:08 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_chars_and_counts(t_game *g)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!count_and_validate_chars(g, &p, &e, &c))
		return (0);
	if (p != 1 || e != 1 || c < 1)
	{
		ft_printf("Error\nMap must have 1 P, 1 E and at least 1 C\n");
		return (0);
	}
	return (1);
}

int	validate_rectangle(char **map)
{
	int	width;
	int	y;

	if (!map || !map[0])
	{
		ft_printf("Error\nMap is empty or invalid\n");
		return (0);
	}
	width = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) != width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	validate_walls(char **map)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (ft_printf("Error\nHOW do you want me to play an OPEN map\n"), 0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (ft_printf("Error\nHOW do you want me to play an OPEN map\n"), 0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *g)
{
	if (!validate_rectangle(g->map))
		return (0);
	if (!validate_chars_and_counts(g))
		return (0);
	if (!validate_walls(g->map))
		return (0);
	find_player(g);
	if (!validate_path(g))
		return (0);
	return (1);
}
