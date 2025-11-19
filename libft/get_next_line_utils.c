/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:51:00 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/12 16:18:10 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	j;
	char	*str;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*get_line(const char *line)
{
	size_t		i;
	char		*s;
	size_t		j;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s[j] = line[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*save_rest(char *line)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	rest = malloc(ft_strlen(line) - i + 1);
	if (!rest)
		return (free(line), NULL);
	while (line[i])
		rest[j++] = line[i++];
	rest[j] = '\0';
	free(line);
	return (rest);
}
