/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 16:34:44 by mpeskov          ###   ########.fr       */
/*   Updated: 2026/01/14 15:27:43 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(char *arg, t_config *config)
{
	if (!ft_strncmp("--bench", arg, 8) && ft_strlen(arg) == 7)
		return (config->bench = 1, 1);
	else if (!ft_strncmp("--adaptive", arg, 11) && ft_strlen(arg) == 10)
		return (config->mode = MODE_ADAPTIVE, 1);
	else if (!ft_strncmp("--simple", arg, 9) && ft_strlen(arg) == 8)
		return (config->mode = MODE_SIMPLE, 1);
	else if (!ft_strncmp("--medium", arg, 9) && ft_strlen(arg) == 8)
		return (config->mode = MODE_MEDIUM, 1);
	else if (!ft_strncmp("--complex", arg, 10) && ft_strlen(arg) == 9)
		return (config->mode = MODE_COMPLEX, 1);
	else
		return (0);
}

static int	parse_flags(int *argc, char **argv, t_config *config)
{
	int	i;
	int	ac;

	ac = *argc;
	i = 1;
	while (i < ac)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!handle_flag(argv[i], config))
				return (0);
			argv[i] = "";
			*argc -= 1;
		}
		i++;
	}
	return (1);
}

static void	sort(t_stack **a, t_stack **b, t_config *config, t_bench *bench)
{
	int		disorder;

	disorder = compute_disorder(*a);
	bench->disorder = disorder;
	if (disorder == 0)
	{
		bench->strat = ft_strdup("NONE");
		return ;
	}
	if (config->mode == MODE_ADAPTIVE)
	{
		if (disorder < 2000)
			selection_sort(a, b, bench);
		else if (
			(disorder >= 2000 && disorder < 5000) || stacksize(*a) < 150)
			chunk_sort(a, b, bench);
		else
			radix_sort(a, b, bench);
	}
	else if (config->mode == MODE_SIMPLE)
		selection_sort(a, b, bench);
	else if (config->mode == MODE_MEDIUM)
		chunk_sort(a, b, bench);
	else
		turk_sort(a, b, bench);
}

static int	check_input(int *argc, char **argv, t_config *config)
{
	if (!parse_flags(argc, argv, config))
	{
		write(2, "Error parsing input\n", 20);
		return (0);
	}
	if (!check_args(*argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_config	*config;
	t_bench		bench;

	if (argc == 1)
		return (0);
	config = init_config();
	bench = init_bench();
	if (!check_input(&argc, argv, config))
		return (1);
	stack_a = init_stack(argv, argc);
	stack_b = NULL;
	sort(&stack_a, &stack_b, config, &bench);
	if (config->bench)
		print_bench(&bench);
	free_all(stack_a, stack_b, &bench, config);
	return (0);
}
