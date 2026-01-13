/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:02:16 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/13 16:05:24 by mvazquez         ###   ########.fr       */
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
	stack->previous = NULL;
	stack->next = NULL;
	return (stack);
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
	(*stack)->previous = new;
	*stack = new;
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
}

size_t	stacksize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
