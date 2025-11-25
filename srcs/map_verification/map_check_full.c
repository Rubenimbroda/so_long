/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:43:17 by rubenior          #+#    #+#             */
/*   Updated: 2025/11/25 12:32:42 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_many_cep(char **map, int height, int length)
{
	int	many_c;
	int	many_e;
	int	many_p;
	int	i;

	i = -1;
	many_c = 0;
	many_e = 0;
	many_p = 0;
	while (++i < height)
	{
		while (map[i][length])
		{
			if (map[i][length] == 'C')
				many_c++;
			if (map[i][length] == 'E')
				many_e++;
			if (map[i][length++] == 'P')
				many_p++;
		}
		length = 0;
	}
	if (many_c == 0 || many_p != 1 || many_e != 1)
		return (1);
	return (0);
}

int	check_closed(char **map, int height, int length)
{
	int	i;

	i = -1;
	height--;
	length = length - 2;
	while (++i < length)
		if (map[0][i] != '1')
			return (1);
	i = 1;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][length] != '1')
			return (1);
		i++;
	}
	i = -1;
	while (++i < length)
		if (map[height][i] != '1') 
			return (1);
	return (0);
}

int	creating_map(t_all *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	data->map.map = (char **)malloc(sizeof(char *) * (data->map.h + 1));
	while (i < data->map.h)
	{
		data->map.map[i] = ft_strdup(line);
		search_npc(line, i, data);
		if (data->map.map[i] == NULL)
			return (free_error_int(data->map.map, 0, data->map.h));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	data->map.map[i] = NULL;
	close (fd);
	return (0);
}

int	get_size(int fd, t_all *data)
{
	char	*str;
	int		many_lines;

	many_lines = 0;
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	data->map.w = ft_strlen(str);
	while (str != NULL)
	{
		if (str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = '\0';
		if (ft_strlen(str) != (size_t)data->map.w
			|| check_characters(str) == 1)
			return (free(str), 0);
		many_lines++;
		free(str);
		str = get_next_line(fd);
	}
	free (str);
	return (many_lines);
}

int	map_check_full(char *filename, t_all *data)
{
	char	**dup_map;
	int		fd;

	data->player.moves = 0;
	data->map.many_colect = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (6);
	data->map.h = get_size(fd, data);
	if (data->map.h == 0)
		return (1);
	close (fd);
	fd = open(filename, O_RDONLY);
	if (creating_map(data, fd) == 1)
		return (5);
	data->map.w = ft_strlen(data->map.map[0]);
	if (check_closed(data->map.map, data->map.h, data->map.w) == 1)
		return (2);
	if (check_many_cep(data->map.map, data->map.h, 0) == 1)
		return (3);
	dup_map = dupmap(data);
	if (check_possible(dup_map, data) == 1)
		return (free_error_int(dup_map, 4, data->map.h));
	free_error_int(dup_map, 0, data->map.h);
	return (0);
}
