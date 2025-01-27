/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:19:06 by bdenk             #+#    #+#             */
/*   Updated: 2025/01/26 19:32:01 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(long int n)
{
	int		i;
	char	c;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
	}
	c = n % 10 + '0';
	ft_putchar(c);
	i++;
	return (i);
}

int	ft_puthex_low(unsigned long int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_low(n / 16);
	digit = n % 16;
	if (digit < 10)
	{
		count += ft_putchar('0' + digit);
	}
	else
	{
		count += ft_putchar('a' + (digit - 10));
	}
	return (count);
}

int	ft_puthex_up(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_up(n / 16);
	digit = n % 16;
	if (digit < 10)
	{
		count += ft_putchar('0' + digit);
	}
	else
	{
		count += ft_putchar('A' + (digit - 10));
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	adress;
	int			count;

	adress = (uintptr_t)ptr;
	count = 0;
	if (!adress)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex_low(adress);
	}
	return (count);
}
