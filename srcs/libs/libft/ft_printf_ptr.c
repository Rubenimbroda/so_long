/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:53:37 by rnuno-im          #+#    #+#             */
/*   Updated: 2025/11/06 15:28:41 by rnuno-im         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long long)ptr;
	ft_putstr("0x");
	len = 2;
	len += ft_puthex_low(addr);
	return (len);
}
