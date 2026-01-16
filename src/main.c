/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/16 15:54:20 by mvazquez         ###   ########.fr       */
/*   Updated: 2026/01/14 15:27:43 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int print_i, int print_curri, int tg_val)
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
		if (print_curri)
			ft_printf("(%i)", stack->current_i);
		if (tg_val && stack->target_node)
			ft_printf("(%i)", stack->target_node->value);
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
	stack_b = stacknew(4);
	stackadd_back(&stack_b, stacknew(9));
	stackadd_back(&stack_b, stacknew(2));
	stackadd_back(&stack_b, stacknew(5));

	print_stack(stack, 1, 1, 0);
	assign_target_node(&stack, &stack_b);
	print_stack(stack_b, 0, 0, 1);
	return (0);
}
