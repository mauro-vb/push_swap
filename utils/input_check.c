/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:24:48 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 15:28:04 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int num, char **nums)
{
	size_t	i;
	int		tmp;

	i = 1;
	while (nums[i])
	{
		tmp = ft_atoi(nums[i]);
		if (num == tmp)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *str)
{
	if (!(*str))
		return (1);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	free_split(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		free(strs[i]);
	free(strs);
}

char	*get_input_str(char **argv)
{
	char	**res;
	int		i;

	i = 1;
	res = argv;
	while (res[i][0] == '\0')
		i++;
	return (res[i]);
}

int	check_args(int argc, char **argv)
{
	long	num;
	char	**split_ptr;
	char	**args;
	size_t	i;

	if (argc == 2)
		args = ft_split(get_input_str(argv), " ");
	else
		args = ++argv;
	if (!args)
		return (0);
	i = 0;
	split_ptr = args;
	while (*args)
	{
		if (!is_num(*args))
			return (0);
		if (*args[0] != '\0')
		{
			num = ft_atol(*args);
			if (has_duplicate(num, args) || num > INT_MAX || num < INT_MIN)
				return (0);
		}
		i++;
		args++;
	}
	if (argc == 2)
		free_split(split_ptr, i);
	return (1);
}
