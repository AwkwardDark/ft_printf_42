/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:58:59 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/20 21:57:40 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(va_list args, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'p')
		*len += ft_puthex(va_arg(args, unsigned long), 0);
	else if (c == 'x')
		*len += ft_puthex(va_arg(args, unsigned long), 0);
	else if (c == 'X')
		*len += ft_puthex(va_arg(args, unsigned long), 1);
	else if (c == '%')
		*len += ft_putchar('%');
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			ft_parsing(args, str[i++ + 1], &len);
		else if (str[i] == '%' && !str[i + 1])
			return (-1);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("\nIt counts: %d", ft_printf("Exemple:%s, une lettre:%c et %%", av[1], av[2][0]));
	}
	return (0);
}
