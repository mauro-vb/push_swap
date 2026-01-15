/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:54:07 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/15 13:14:57 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value > (tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	bubble_sort(t_stack **stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	while (!is_sorted(*stack))
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		ra(stack);
	}
}
