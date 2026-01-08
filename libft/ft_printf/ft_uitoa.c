/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:38:21 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/08 12:51:42 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned long	nb;
	size_t			len;
	char			*res;

	nb = n;
	len = get_len(nb);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}
