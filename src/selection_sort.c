/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:39 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 15:33:48 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort0(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index == i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			rra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
