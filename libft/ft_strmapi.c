/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:30:09 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/15 14:33:36 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	res = ft_strdup(s);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (res[i])
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
