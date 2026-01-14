/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:05:34 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/14 14:07:13 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	head = *stack;
	min = NULL;
	has_min = 0;
	while (1)
	{
		if ((head->index == -1) && (!has_min || head->value < min->value))
		{
			min = head;
			has_min = 1;
		}
		head = head->next;
		if (head == *stack)
			break ;
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	int		index;
	int		size;
	t_stack	*head;

	index = 0;
	size = stacksize(*stack);
	while (index < size)
	{
		head = get_next_min(stack);
		head->index = index++;
	}
}
