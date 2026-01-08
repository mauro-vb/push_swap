/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:07:18 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/26 18:07:53 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec_putnbr(unsigned int n, char *base, unsigned int bn, size_t *c)
{
	if (n >= bn)
		rec_putnbr(n / bn, base, bn, c);
	ft_putchar_pf(base[n % bn], c);
}

void	ft_puthex_pf(unsigned int n, int uppercase, size_t *counter)
{
	char	*base;

	if (uppercase)
		base = HEX_UPP_BASE;
	else
		base = HEX_LOW_BASE;
	rec_putnbr(n, base, 16, counter);
}
