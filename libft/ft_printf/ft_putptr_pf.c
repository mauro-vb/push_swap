/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:57:19 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/26 18:17:36 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recur(unsigned long n, char *base, unsigned long bn, size_t *c)
{
	if (n >= bn)
		recur(n / bn, base, bn, c);
	ft_putchar_pf(base[n % bn], c);
}

static void	ft_puthex_ul(unsigned long n, int uppercase, size_t *counter)
{
	char	*base;

	if (uppercase)
		base = HEX_UPP_BASE;
	else
		base = HEX_LOW_BASE;
	recur(n, base, 16, counter);
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	if (ptr_address == 0)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	ft_putstr_pf("0x", counter);
	ft_puthex_ul(ptr_address, 0, counter);
}
