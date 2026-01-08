/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:46:37 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/15 14:55:59 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *counter)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_pf(str, counter);
	free(str);
}

void	ft_putunbr_pf(unsigned int n, size_t *counter)
{
	char	*str;

	str = ft_uitoa(n);
	ft_putstr_pf(str, counter);
	free(str);
}
