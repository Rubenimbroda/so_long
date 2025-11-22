/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:41:25 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/05 08:13:33 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*trim_n(char *str);
char	*get_next_line(int fd);
char	*new_cache(char *cache);
char	*ft_strdup_g(const char *str);
char	*ft_strjoin_g(char *s1, char *s2);
char	*free_all(char *cache, char *buffer);
char	*when_found_nl(char *buffer, char *cache, int fd);

int		check_read(char *buffer, char *cache, int index, int flag);
int		search_for_nl(const char *str);
int		ft_strlen_g(const char *str);

#endif
