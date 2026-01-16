/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:04:26 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/16 16:00:57 by mvazquez         ###   ########.fr       */
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

void	assign_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_b;

	tmp_b = *stack_b;
	if (is_biggest(tmp_b->value, stack_a))
		tmp_b->target_node = *stack_a;
	else
		tmp_b->target_node = smallest_bigger(tmp_b->value, stack_a);
	tmp_b = tmp_b->next;
	while (tmp_b != *stack_b)
	{
		if (is_biggest(tmp_b->value, stack_a))
			tmp_b->target_node = *stack_a;
		else
			tmp_b->target_node = smallest_bigger(tmp_b->value, stack_a);
		tmp_b = tmp_b->next;
	}
}
