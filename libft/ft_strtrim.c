/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <mvazquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:05:28 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/15 12:32:53 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	end = ft_strlen(s);
	while (s[end - 1] && ft_strchr(set, s[end - 1]))
		end--;
	return (ft_substr(s, start, end - start));
}
