/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:46:59 by bdenk             #+#    #+#             */
/*   Updated: 2025/01/27 17:16:27 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_specifiers(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_low(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_up(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	const char	*ptr;

	ptr = format;
	count = 0;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			count += ft_specifiers(args, *ptr);
		}
		else
		{
			count += ft_putchar(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return (count);
}
