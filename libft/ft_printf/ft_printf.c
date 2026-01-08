/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:54:46 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/26 18:12:48 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putunbr_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'x')
		ft_puthex_pf(va_arg(va, int), 0, counter);
	else if (*str == 'X')
		ft_puthex_pf(va_arg(va, int), 1, counter);
	if (*str == '%')
		ft_putchar_pf('%', counter);
}

int	ft_printf(const char *str, ...)
{
	size_t	res;
	va_list	va;

	if (!str)
		return (0);
	res = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &res);
		}
		else
			ft_putchar_pf(*str, &res);
		str++;
	}
	va_end(va);
	return (res);
}
