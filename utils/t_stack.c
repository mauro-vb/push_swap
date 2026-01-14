/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:02:16 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/14 14:12:00 by mpeskov          ###   ########.fr       */
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
	stack->index = -1;
	stack->previous = stack;
	stack->next = stack;
	return (stack);
}

t_stack	*stacklast(t_stack *stack)
{
	return (stack->previous);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!stack || !new)
		return ;
	tail = (*stack)->previous;
	new->next = *stack;
	new->previous = tail;
	(*stack)->previous = new;
	tail->next = new;
	*stack = new;
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stacklast(*stack);
	last->next = new;
	new->previous = last;
	(*stack)->previous = new;
}

size_t	stacksize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp != head->previous)
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

void	stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->previous)
		stack->previous->next = stack->next;
	if (stack->next)
		stack->next->previous = stack->previous;
	free(stack);
}
