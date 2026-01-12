/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:29 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/12 11:40:00 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int print_i)
{
	if (!stack)
		return ;
	ft_printf("{");
	while (stack)
	{
		ft_printf(" %i", stack->value);
		if (print_i)
			ft_printf("(%i)", stack->index);
		if (stack->next)
			ft_printf(", ");
		stack = stack->next;
	}
	ft_printf(" }\n");
}

int main(int argc, char **argv)
{
	ft_printf("\n\n\n--- TEST ---\n\n");
	ft_printf("\nargc = %i\nargv[0] = \"%s\"\n", argc, argv[0]);

	int	i = 0;
	t_stack *stack = stacknew(1);
	t_stack *new;
	while (i < 20)
	{
		new = stacknew(rand());
		stackadd_front(&stack, new);
		i++;
	}
	print_stack(stack, 0);
	float	dis = compute_disorder(stack);
	int	percent = dis*100.0;
	ft_printf("disorder of 0.%i\n", percent);

	return (0);
}
