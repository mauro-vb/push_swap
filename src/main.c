/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 13:03:12 by mvazquez         ###   ########.fr       */
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

static int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;
	int	flagset;

	i = 1;
	flagset = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!flagset)
			{
				if (!handle_flag(argv[i], config))
					return (0);
				flagset = 1;
			}
			argv[i] = "";
		}
		i++;
	}
	return (1);
}

static t_stack	*init_stack(char **argv, int argc)
{
	char	**args;
	t_stack	*head;
	t_stack	*tmp;

	if (argc == 2)
		args = ft_split(argv[1], " ");
	else
		args = argv + 1;
	while (*args[0] == '\0')
		args++;
	head = stacknew(ft_atoi(*args));
	tmp = head;
	args++;
	while (*args)
	{
		if (*args[0] != '\0')
		{
			tmp = stacknew(ft_atoi(*args));
			stackadd_back(&head, tmp);
		}
		args++;
	}
	index_stack(&head);
	current_index_stack(&head);
	return (head);
}

static void	sort(t_stack **stack_a, t_stack **stack_b, t_config *config)
{
	float		disorder;

	if (config->mode == MODE_ADAPTIVE)
	{
		disorder = compute_disorder(*stack_a);
		if (disorder < 0.2)
			selection_sort(stack_a, stack_b);
		else if (
			(disorder >= 0.2 && disorder < 0.5) || stacksize(*stack_a) < 150)
			chunk_sort(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
	else if (config->mode == MODE_SIMPLE)
		selection_sort(stack_a, stack_b);
	else if (config->mode == MODE_MEDIUM)
		chunk_sort(stack_a, stack_b);
	else
		turk_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_config	*config;
	float		disorder;
	t_bench		bench;

	config = (t_config *)malloc(sizeof(t_config *));
	config->bench = 0;
	bench = init_bench();
	if (!parse_flags(argc, argv, config))
	{
		write(2, "Error parsing input\n", 20);
		return (1);
	}
	if (!check_args(argc, argv))
	{
		write(2, "Error", 12);
		return (0);
	}
	stack_a = init_stack(argv, argc);
	stack_b = NULL;
	if (config->mode == MODE_ADAPTIVE)
	{
		disorder = compute_disorder(stack);
		bench.disorder = disorder;
		if (disorder < 0.2)
		{
			bench.strat = ft_strdup("Selection sort / O(n^2)");
			selection_sort0(&stack, &stack_b, &bench);
		}

		else if (disorder >= 0.2 && disorder < 0.5)
		{
			bench.strat = "Chunk sort / O(n * sqrt(n)";
			chunk_sort(&stack, &stack_b, &bench);
		}
		else
		{
			bench.strat = "Radix sort / O(n * log(n)";
			radix_sort(&stack, &stack_b, &bench);
		}
	}
	else if (config->mode == MODE_SIMPLE)
	{
		bench.strat = "Selection sort / O(n^2)";
		selection_sort0(&stack, &stack_b, &bench);
	}
	else if (config->mode == MODE_MEDIUM)
	{
		bench.strat = "Chunk sort / O(n * sqrt(n)";
		chunk_sort(&stack, &stack_b, &bench
		);
	}
	else
	{
		bench.strat = "Turk sort / O(n * log(n)";
		turk_sort(&stack, &stack_b, &bench);
	}
	if (config->bench)
		print_bench(&bench);
	sort(&stack_a, &stack_b, config);
	return (0);
}
