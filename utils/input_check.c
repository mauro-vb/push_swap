/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:24:48 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 14:07:55 by mvazquez         ###   ########.fr       */
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

int	check_args(int argc, char **argv)
{
	size_t	i;
	long	num;
	char	**args;

	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ++argv;
	if (!args)
		return (0);
	while (*args)
	{
		if (!is_num(*args))
			return (0);
		num = ft_atoi(*args);
		if (has_duplicate(num, args))
			return (0);
		args++;
	}
	return (1);
}
