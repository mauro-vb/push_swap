/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:45:15 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/22 11:49:44 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	int		max_bits;
	t_stack	*head;

	if (!stack)
		return (0);
	head = stack;
	max = head->index;
	while (head->next != stack)
	{
		head = head->next;
		if (head->index > max)
			max = head->index;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	bench->strat = "Radix sort / 0(n * log(n))";
	size = stacksize(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a, bench);
			else
				pb(stack_a, stack_b, bench);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		i++;
	}
}
