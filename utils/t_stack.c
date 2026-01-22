/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:02:16 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/22 11:03:00 by mpeskov          ###   ########.fr       */
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

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = (*stack)->previous;
	new->next = *stack;
	new->previous = tmp;
	tmp->next = new;
	(*stack)->previous = new;
}

size_t	stacksize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	if (!head)
		return (0);
	tmp = head;
	i = 0;
	while (tmp != head->previous)
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

t_stack	*smallest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	min = *stack;
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*biggest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	max = *stack;
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
/*
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

t_stack	*stacklast(t_stack *stack)
{
	return (stack->previous);
}
*/
