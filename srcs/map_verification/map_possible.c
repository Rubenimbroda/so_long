/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:27:15 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/25 20:20:04 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_fill(char c)
{
	return (c == '0' || c == 'C' || c == 'E' || c == 'P');
}

void	flood_fill(char **map, int x, int y, int h, int w)
{
	if (x < 0 || y < 0 || x >= w || y >= h)
		return ;
	if (!can_fill(map[y][x]))
		return ;
	map[y][x] = '2';
	flood_fill(map, x + 1, y, h, w);
	flood_fill(map, x - 1, y, h, w);
	flood_fill(map, x, y + 1, h, w);
	flood_fill(map, x, y - 1, h, w);
}

void	check_path(t_all *data)
{
	int	px;
	int	py;

	px = data->player.x;
	py = data->player.y;
	flood_fill(data->map.map, px, py, data->map.h, data->map.w);
}

int	final_check(char **map, int height, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < length)
	{
		if (map[height][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][length - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	validate_flood(char **map, int h, int w)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
