/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:33:22 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/27 14:10:50 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**duplicate_map(char **map)
{
	int		i;
	int		y;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < i)
	{
		copy[y] = ft_strdup(map[y]);
		y++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_and_validate_chars(t_game *g, int *p, int *e, int *c)
{
	int		y;
	int		x;
	char	ch;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			ch = g->map[y][x];
			if (ch != '0' && ch != '1' && ch != 'C'
				&& ch != 'E' && ch != 'P')
				return (ft_printf("Error\nInvalid character '%c'\n", ch), 0);
			if (ch == 'P')
				(*p)++;
			if (ch == 'E')
				(*e)++;
			if (ch == 'C')
				(*c)++;
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	validate_path(t_game *g)
{
	int		y;
	int		x;
	char	**copy;

	copy = duplicate_map(g->map);
	if (!copy)
		return (0);
	flood_fill(copy, g->player_x, g->player_y);
	y = 0;
	while (copy[y])
	{
		x = 0;
		while (copy[y][x])
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_map(copy);
				return (ft_printf("Error\nC or E is inaccessible\n"), 0);
			}
			x++;
		}
		y++;
	}
	free_map(copy);
	return (1);
}
