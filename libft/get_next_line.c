/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:50:55 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:16 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_join(int fd, char *rest)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(rest, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		else if (bytes < 0)
			return (free(buffer), free(rest), NULL);
		buffer[bytes] = '\0';
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free(buffer), free(temp), NULL);
	}
	free(buffer);
	if (bytes == -1)
		return (free(rest), NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = read_and_join(fd, rest);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = get_line(rest);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	rest = save_rest(rest);
	return (line);
}

/* #include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line;

	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	get_next_line(-1);
	close(fd);
	return 0;
} */