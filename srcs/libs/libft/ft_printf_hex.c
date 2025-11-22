/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:42:02 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:51 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_low(unsigned long long n)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_low(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_puthex_upper(unsigned long long n)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_upper(n / 16);
	len += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}
