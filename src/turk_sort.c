/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:23 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/17 15:40:27 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	int		cost;
	int		min;

	min = (*stack)->totop_cost + (*stack)->target_node->totop_cost;
	tmp = *stack->next;
	while (tmp->next != *stack)
	{
		cost = tmp->totop_cost + tmp->target_node->totop_cost; 
		if (cost < min)
			min = cost;
		tmp = tmp->next;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (stacksize(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a, 1);
	assign_target_node(stack_a, stack_b);
	assign_totop_cost(stack_a);
	assign_totop_cost(stack_b);

}
