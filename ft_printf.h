/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:35:40 by bdenk             #+#    #+#             */
/*   Updated: 2025/01/26 19:34:41 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_putnbr(long int n);
int	ft_puthex_low(unsigned long int n);
int	ft_puthex_up(unsigned int n);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif
