/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:23 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/17 17:26:47 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	int		cost;
	int		min;

	min = (*stack)->totop_cost + (*stack)->target_node->totop_cost;
	tmp = (*stack)->next;
	while (tmp->next != *stack)
	{
		cost = tmp->totop_cost + tmp->target_node->totop_cost; 
		if (cost < min)
			min = cost;
		tmp = tmp->next;
	}
	return (tmp);
}

static void	assign_rotations(
	t_stack *node,
	t_stack **stack_a,
	t_stack **stack_b,
	int (**rot_a)(t_stack **),
	int (**rot_b)(t_stack **)
)
{
	if (node->target_node->current_i <= stacksize(*stack_a) / 2)
		*rot_a = ra;
	else
		*rot_a = rra;
	if (node->current_i <= stacksize(*stack_b) / 2)
		*rot_b = rb;
	else
		*rot_b = rrb;
}

void	rotate_push(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int		(*rot_a)(t_stack **);
	int		(*rot_b)(t_stack **);
	
	assign_rotations(node, stack_a, stack_b, &rot_a, &rot_b);	
	if (rot_a == rot_b)
	{
		while (*stack_a != node->target_node && *stack_b != node)
		{
			if (rot_a == ra)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
		}
	}
	while (*stack_a != node->target_node)
		rot_a(stack_a);
	while (*stack_b != node)
		rot_b(stack_b);	
	pa(stack_a, stack_b);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		(*rot_a)(t_stack **);

	while (stacksize(*stack_a) > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a, 1);
	while (stacksize(*stack_b) > 0)
	{
		assign_target_node(stack_a, stack_b);
		assign_totop_cost(stack_a);
		assign_totop_cost(stack_b);
		tmp = get_cheapest(stack_b);
		rotate_push(stack_a, stack_b, tmp);
	}
	tmp = smallest(stack_a);
	if (tmp->current_i <= stacksize(*stack_a))
		rot_a = ra;
	else
		rot_a = rra;
	while (*stack_a != tmp)
		rot_a(stack_a);
}
