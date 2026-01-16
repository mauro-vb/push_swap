/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 16:48:30 by mpeskov          ###   ########.fr       */
/*   Updated: 2026/01/14 15:27:43 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int print_i)
{
	t_stack	*initial;

	if (!stack)
		return ;
	ft_printf("{");
	initial = stack;
	while (1)
	{
		ft_printf(" %i", stack->value);
		if (print_i)
			ft_printf("(%i)", stack->index);
		ft_printf(", ");
		stack = stack->next;
		if (stack == initial)
			break ;
	}
	ft_printf(" }\n");
}

int	handle_flag(char *arg, t_config *config)
{
	if (!ft_strncmp("--bench", arg, 8) && ft_strlen(arg) == 7)
	{
		*config->bench = 1;
		return (1);
	}
	else if (!ft_strncmp("--adaptive", arg, 11) && ft_strlen(arg) == 10)
	{
		*config->mode = MODE_ADAPTIVE;
		return (1);
	}
	else if (!ft_strncmp("--simple", arg, 9) && ft_strlen(arg) == 8)
	{
		*config->mode = MODE_SIMPLE;
		return (1);
	}
	else if (!ft_strncmp("--medium", arg, 9) && ft_strlen(arg) == 8)
	{
		*config->mode = MODE_MEDIUM;
		return (1);
	}
	else if (!ft_strncmp("--complex", arg, 10) && ft_strlen(arg) == 9)
	{
		*config->mode = MODE_COMPLEX;
		return (1);
	}
	else
		return (0);
	

int	parse_flags(int argc, char **argv, t_config *config)
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
				if (!handle_flag(argv[i], &config))
				{
					write(2, "Flags error\n", 12);
					return (0);
				flagset = 1;
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
	//int		i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	head = stacknew(ft_atoi(*args));
	tmp = head;
	args++;
	while (*args)
	{
		tmp = stacknew(ft_atoi(*args));
		stackadd_back(&head, tmp);
		args++;
	}
	index_stack(&head);
	return (head);
}

int main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;


	if (!check_args(argc, argv))
	{
		ft_printf("Bad Input...");
		return (0);
	}
	
	stack = init_stack(argv, argc);
	stack_b = NULL;

	print_stack(stack, 1);
	radix_sort(&stack, &stack_b);	
	print_stack(stack, 1);

	return (0);
}
