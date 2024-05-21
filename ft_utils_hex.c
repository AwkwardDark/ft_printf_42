/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:58:59 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:02 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, int b)
{
	int		len;
	char	*hexlow;
	char	*hexup;

	len = 0;
	hexlow = "0123456789abcdef";
	hexup = "0123456789ABCDEF";
	if (b)
	{
		if (n > 15)
			len += ft_puthex(n / 16, 1);
	len += ft_putchar(hexup[n % 16]);
	}
	else
	{
		if (n > 15)
			len += ft_puthex(n / 16, 0);
		len += ft_putchar(hexlow[n % 16]);
	}
	return (len);
}

int	ft_ptradd(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex(n, 0);
	return (len);
}
