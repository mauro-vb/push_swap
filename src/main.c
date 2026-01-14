/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/14 14:41:42 by mvazquez         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	ft_printf("\n\n\n TEST \n\n");
	int	check_args_res = check_args(argc, argv);
	ft_printf("check args returned %i\n", check_args_res);

	int	i = 0;
	t_stack *stack = stacknew(-1);
	t_stack *new;
	while (i < 20)
	{
		new = stacknew(rand());
		stackadd_front(&stack, new);
		i++;
	}
	index_stack(&stack);
	print_stack(stack, 1);
	ra(&stack);
	print_stack(stack, 1);
	sa(&stack);
	print_stack(stack, 1);
	rra(&stack);
	print_stack(stack, 1);
	sa(&stack);
	print_stack(stack, 1);

	return (0);
}
