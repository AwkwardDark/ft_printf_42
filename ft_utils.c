/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:58:59 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/20 21:57:18 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
		len += ft_putchar(str[i++]);
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = (long)n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar((nb % 10) + 48);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

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
			len += ft_puthex(n / 16, b);
	len += ft_putchar(hexup[n % 16]);
	}
	else
	{
		if (n > 15)
			len += ft_puthex(n / 16, b);
		len += ft_putchar(hexlow[n % 16]);
	}
	return (len);
}
