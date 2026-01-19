/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:23 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/19 17:24:57 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	calculate_actual_cost(t_stack *node, size_t sa, size_t sb)
{
	size_t	cost_a;
	size_t	cost_b;
	size_t	a_top;
	size_t	b_top;

	cost_a = node->totop_cost;
	cost_b = node->target_node->totop_cost;
	a_top = node->current_i <= sa / 2;
	b_top = node->target_node->current_i <= sb / 2;
	if (a_top == b_top)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static t_stack	*get_cheapest(t_stack **stack_a, size_t size_a, size_t size_b)
{
	t_stack		*tmp;
	t_stack		*best;
	int			cost;
	int			min;

	min = 2147483647;
	best = (*stack_a);
	tmp = (*stack_a);
	while (1)
	{
		cost = calculate_actual_cost(tmp, size_a, size_b);
		if (cost < min)
		{
			min = cost;
			best = tmp;
		}
		tmp = tmp->next;
		if (tmp == *stack_a)
			break ;
	}
	return (best);
}

static int	(*rotation(t_stack *node, t_stack **stack, int is_a))(t_stack **s)
{
	size_t	pos;
	size_t	size;

	size = stacksize(*stack);
	if (is_a)
		pos = node->current_i;
	else
		pos = node->target_node->current_i;
	if (pos <= size / 2)
	{
		if (is_a)
			return (ra);
		return (rb);
	}
	else
	{
		if (is_a)
			return (rra);
		return (rrb);
	}
}

void	rotate_push(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int		(*rot_a)(t_stack **);
	int		(*rot_b)(t_stack **);

	rot_a = rotation(node, stack_a, 1);
	rot_b = rotation(node, stack_b, 0);
	if (*rot_a == *rot_b)
	{
		while (*stack_b != node->target_node && *stack_a != node)
		{
			if (*rot_b == rb)
				rr(stack_a, stack_b);
			else
				rrr(stack_a, stack_b);
		}
	}
	while (*stack_b != node->target_node)
		(*rot_b)(stack_b);
	while (*stack_a != node)
		(*rot_a)(stack_a);
	pb(stack_a, stack_b);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		(*rot_b)(t_stack **);

	while (stacksize(*stack_b) < 3)
		pb(stack_a, stack_b);
	sort_three(stack_b, 0);
	while (stacksize(*stack_a) > 0)
	{
		current_index_stack(stack_a); 
		current_index_stack(stack_b);
		assign_target_node(stack_b, stack_a);
		assign_totop_cost(stack_a);
		assign_totop_cost(stack_b);
		tmp = get_cheapest(stack_a, stacksize(*stack_a), stacksize(*stack_b));
		rotate_push(stack_a, stack_b, tmp);
	}
	tmp = biggest(stack_b);
	if (tmp->current_i <= stacksize(*stack_b) / 2)
		rot_b = rb;
	else
		rot_b = rrb;
	while (*stack_b != tmp)
		rot_b(stack_b);
	while (*stack_b)
	{
		tmp = biggest(stack_b);
		if (*stack_b == tmp)
			pa(stack_a, stack_b);
		else
		{
			if (tmp->current_i <= stacksize(*stack_b) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}
/*
static void	assign_rotations(
	t_stack *node,
	t_stack **stack_a,
	t_stack **stack_b,
	int (**rot_a)(t_stack **),
	int (**rot_b)(t_stack **)
)
{
	if (node->target_node->current_i <= stacksize(*stack_b) / 2)
		*rot_b = rb;
	else
		*rot_b = rrb;
	if (node->current_i <= stacksize(*stack_a) / 2)
		*rot_a = ra;
	else
		*rot_a = rra;
}
*/
