/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:38:21 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/15 14:28:36 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = n;
	len = get_len(nb);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	res[len] = '\0';
	while (len > 0)
	{
		len--;
		res[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	return (res);
}
