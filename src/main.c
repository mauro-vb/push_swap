/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 15:55:26 by mvazquez         ###   ########.fr       */
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

	ft_printf("\n\n\n TEST \n\n");
	if (!check_args(argc, argv))
	{
		ft_printf("Bad Input...");
		return (0);
	}
	
	stack = init_stack(argv, argc);
	stack_b = NULL;

	print_stack(stack, 1);
	double_selection_sort(&stack, &stack_b);	
	print_stack(stack, 1);

	return (0);
}
