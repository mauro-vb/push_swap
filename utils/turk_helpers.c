/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:04:26 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/18 17:10:24 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_biggest(int value, t_stack **stack_a)
{
	t_stack	*tmp;

	if ((*stack_a)->value > value)
		return (0);
	tmp = (*stack_a)->next;
	while (tmp != *stack_a)
	{
		if (tmp->value > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


t_stack	*smallest_bigger(int value, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack_a;
	if (value < tmp->value)
		min = tmp;
	else
		min = NULL;
	tmp = tmp->next;	
	while (tmp != *stack_a)
	{
		if (value < tmp->value && (!min || tmp->value < min->value))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
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

void	assign_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_b;

	tmp_b = *stack_b;
	if (is_biggest(tmp_b->value, stack_a))
		tmp_b->target_node = smallest(stack_a);
	else
		tmp_b->target_node = smallest_bigger(tmp_b->value, stack_a);
	tmp_b = tmp_b->next;
	while (tmp_b != *stack_b)
	{
		if (is_biggest(tmp_b->value, stack_a))
			tmp_b->target_node = smallest(stack_a);
		else
			tmp_b->target_node = smallest_bigger(tmp_b->value, stack_a);
		tmp_b = tmp_b->next;
	}
}

void	assign_totop_cost(t_stack **stack)
{
	size_t	size;
	t_stack	*tmp;

	size = stacksize(*stack);
	tmp = *stack;
	while (1)
	{
		if (tmp->current_i <= size / 2)
			tmp->totop_cost = tmp->current_i;
		else
			tmp->totop_cost = size - tmp->current_i;
		tmp = tmp->next;
		if (tmp->next == *stack)
			break ;
	}
}
