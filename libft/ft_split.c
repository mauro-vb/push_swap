/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:07:41 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 16:15:41 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_words(char *s, char *c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_in_set(s[i], c))
			i++;
		if (s[i] && !is_in_set(s[i], c))
			count++;
		while (s[i] && !is_in_set(s[i], c))
			i++;
	}
	return (count);
}

static char	*malloc_word(char *s, char *c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && !is_in_set(s[len], c))
		len++;
	word = malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[i] && !is_in_set(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_arr(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

char	**ft_split(char const *s, char *c)
{
	char	**arr;
	char	*ptr;
	size_t	nwords;
	size_t	i;

	ptr = (char *)s;
	nwords = count_words(ptr, c);
	arr = malloc((nwords + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i++ < nwords)
	{
		while (is_in_set(*ptr, c))
			ptr++;
		arr[i] = malloc_word(ptr, c);
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		ptr += ft_strlen(arr[i]) + 1;
	}
	arr[nwords] = NULL;
	return (arr);
}
