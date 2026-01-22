/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:24:48 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/22 12:06:44 by mvazquez         ###   ########.fr       */
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

void	check_arg(char **args, int *res)
{
	while (*args && *res == 1)
	{
		if (!is_num(*args))
			*res = 0;
		else if (*args[0] != '\0')
		{
			if (has_duplicate(ft_atol(*args), args)
				|| ft_atol(*args) > INT_MAX || ft_atol(*args) < INT_MIN)
				*res = 0;
		}
		args++;
	}
}

int	check_args(int argc, char **argv)
{
	char	**split_ptr;
	char	**args;
	int		res;

	split_ptr = NULL;
	if (argc == 2)
	{
		args = ft_split(get_input_str(argv), " \n");
		split_ptr = args;
	}
	else
		args = ++argv;
	if (!args)
		return (0);
	res = 1;
	check_arg(args, &res);
	return (free_split(split_ptr), res);
}
