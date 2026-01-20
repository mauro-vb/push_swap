/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:45:03 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/20 11:57:51 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack, int *max_idx)
{
	int		max;
	int		pos;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	max = tmp->index;
	pos = tmp->current_i;
	while (1)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = tmp->current_i;
		}
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	*max_idx = max;
	return (pos);
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	max_idx;
	int	pos;
	int	size;

	while (*stack_b)
	{
		current_index_stack(stack_b);
		size = stacksize(*stack_b);
		pos = find_max_pos(*stack_b, &max_idx);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != max_idx)
				rb(stack_b, bench);
		}
		else
		{
			while ((*stack_b)->index != max_idx)
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
	}
}

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while ((chunk * chunk) <= size)
		chunk++;
	chunk--;
	if (size > 100)
		return (chunk * 1.5);
	return (chunk * 2);
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	i;
	int	range;
	int	chunk_size;
	int	size;

	size = stacksize(*stack_a);
	chunk_size = get_chunk_size(size);
	i = 0;
	range = chunk_size;
	while (*stack_a)
	{
		if ((*stack_a)->index < range)
		{
			pb(stack_a, stack_b, bench);
			if ((*stack_b)->index < i)
				rb(stack_b, bench);
			i++;
			if (i == range)
				range += chunk_size;
		}
		else
			ra(stack_a, bench);
	}
	push_back_to_a(stack_a, stack_b, bench);
}
