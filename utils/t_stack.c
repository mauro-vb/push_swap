/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:02:16 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/08 15:28:35 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = 0;
	stack->previous = NULL;
	stack->next = NULL;
	return (stack);
}

void	set_stack_indexes(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack->next)
	{
		stack->index = i++;
		stack = stack->next;
	}
	stack->index = i;
}

t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	new->previous = NULL;
	*stack = new;
	set_stack_indexes(*stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	last = stacklast(*stack);
	last->next = new;
	new->previous = last;
	(*stack)->previous = NULL;
	set_stack_indexes(*stack);
}
