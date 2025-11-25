/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:38:43 by edvieira          #+#    #+#             */
/*   Updated: 2025/11/25 12:29:16 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *cache, char *buffer)
{
	free (buffer);
	free (cache);
	return (NULL);
}

int	check_read(char *buffer, char *cache, int index, int flag)
{
	if (index <= 0 && flag == 0)
	{
		free_all (buffer, cache);
		return (0);
	}
	if (index < 0 && flag == 1)
	{
		free_all (buffer, cache);
		return (0);
	}
	while (index <= BUFFER_SIZE)
		buffer[index++] = '\0';
	return (1);
}

char	*new_cache(char *cache)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cache[i++] != '\n')
		if (cache[i] == '\0')
			break ;
	temp = (char *)malloc((ft_strlen_g(cache) - i) + 1);
	while (cache[i + j] != '\0')
	{
		temp[j] = cache[i + j];
		j++;
	}
	temp[j] = '\0';
	free (cache);
	if (temp[0] == 0)
	{
		free (temp);
		return (NULL);
	}
	return (temp);
}

char	*when_found_nl(char *buffer, char *cache, int fd)
{
	int		i;
	char	*temp;

	while (search_for_nl(cache) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (check_read(buffer, cache, i, 1) <= 0)
			return (NULL);
		cache = ft_strjoin_g(cache, buffer);
	}
	temp = (char *)malloc(ft_strlen_g(cache) + 1);
	i = 0;
	while (cache[i] != '\0')
	{
		temp[i] = cache[i];
		i++;
	}
	temp[i] = '\0';
	free(cache);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*buffer;
	char		*to_return;
	int			i;

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (cache == NULL || cache[0] == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (check_read(buffer, cache, i, 0) <= 0)
			return (NULL);
		cache = ft_strdup_g(buffer);
	}
	if (search_for_nl(cache) == 0)
	{
		cache = when_found_nl(buffer, cache, fd);
		if (cache == NULL)
			return (NULL);
	}
	to_return = trim_n(ft_strdup_g(cache));
	cache = new_cache(cache);
	free(buffer);
	return (to_return);
}
/*
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*file = "42_with_nl";
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while(str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (0);
}*/
