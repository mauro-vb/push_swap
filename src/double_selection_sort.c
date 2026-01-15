/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_selection_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:39 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 16:30:50 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min_i;
	int	max_i;
	int	max_index;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	max_index = stacksize(*stack_a) - 1;
	min_i = 0;
	max_i = max_index;
	while (*stack_a)
	{
		print_stack(*stack_a, 1);
		ft_printf("min: %i, max: %i\n", min_i, max_i);
		if ((*stack_a)->index == min_i || (*stack_a)->index == max_i)
		{
			if ((*stack_a)->index == min_i)
			{
				if (stacksize(*stack_b) > 1 && min_i != 0)
				{
					while ((*stack_b)->index != min_i - 1)
						rb(stack_b);
				}
				pb(stack_a, stack_b);
				min_i++;
			}
			else if ((*stack_a)->index == max_i)
			{
				if (stacksize(*stack_b) > 1 && max_i != max_index)
				{
					while ((*stack_b)->index != max_i + 1)
						rb(stack_b);
				}
				pb(stack_a, stack_b);
				max_i--;
			}
		}
		else
			ra(stack_a);
	}
	while ((*stack_b)->index != 0)
		rb(stack_b);
	while(*stack_b)
		pa(stack_a, stack_b);
}
