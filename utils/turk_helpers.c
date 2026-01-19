/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:04:26 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/19 17:14:57 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*biggest_smaller(int value, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	if (value > tmp->value)
		max = tmp;
	else
		max = NULL;
	tmp = tmp->next;
	while (tmp != *stack)
	{
		if (value > tmp->value && (!max || tmp->value > max->value))
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
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

void	assign_target_node(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*tmp_src;

	tmp_src = *stack_src;
	while (1)
	{
		if (tmp_src->value < smallest(stack_dest)->value)
			tmp_src->target_node = biggest(stack_dest);
		else
			tmp_src->target_node = biggest_smaller(tmp_src->value, stack_dest);
		tmp_src = tmp_src->next;
		if (tmp_src == *stack_src)
			break ;
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
		if (tmp == *stack)
			break ;
	}
}

/*
t_stack	*smallest_bigger(int value, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	if (value < tmp->value)
		min = tmp;
	else
		min = NULL;
	tmp = tmp->next;
	while (tmp != *stack)
	{
		if (value < tmp->value && (!min || tmp->value < min->value))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static int	is_smallest(int value, t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->value < value)
		return (0);
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value < value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_biggest(int value, t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->value > value)
		return (0);
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value > value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
*/
