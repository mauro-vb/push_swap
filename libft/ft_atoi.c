/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:26:44 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/12 15:03:39 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	res;
	int		neg_mult;

	res = 0;
	neg_mult = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg_mult *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * neg_mult);
}
