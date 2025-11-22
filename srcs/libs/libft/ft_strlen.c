/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenior <rubenior@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:18:47 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/22 00:14:34 by rubenior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char str[])
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* int main()
{
	char	str[] = "me llamo ruben";
	printf("esta frase tiene %i caracteres", ft_strlen(str));
} */