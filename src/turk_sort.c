/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:23 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 14:40:40 by mvazquez         ###   ########.fr       */
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

void	rotate_push(t_stack **a, t_stack **b, t_stack *node, t_bench *bench)
{
	int		(*rot_a)(t_stack **, t_bench*);
	int		(*rot_b)(t_stack **, t_bench*);

	rot_a = get_rot(node, a, 1);
	rot_b = get_rot(node, b, 0);
	if (*rot_a == *rot_b)
	{
		while (*b != node->target_node && *a != node)
		{
			if (*rot_b == rb)
				rr(a, b, bench);
			else
				rrr(a, b, bench);
		}
	}
	while (*b != node->target_node)
		(*rot_b)(b, bench);
	while (*a != node)
		(*rot_a)(a, bench);
	pb(a, b, bench);
}

static void	update_and_push(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	current_index_stack(a);
	current_index_stack(b);
	assign_target_node(b, a);
	assign_totop_cost(a);
	assign_totop_cost(b);
	tmp = get_cheapest(a, stacksize(*a), stacksize(*b));
	rotate_push(a, b, tmp, bench);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	bench->strat = ft_strdup("Turk sort / 0(n * log(n))");
	while (stacksize(*stack_b) < 3)
		pb(stack_a, stack_b, bench);
	sort_three(stack_b, 0, bench);
	while (stacksize(*stack_a) > 0)
		update_and_push(stack_a, stack_b, bench);
	while (*stack_b)
	{
		if (*stack_b == biggest(stack_b))
			pa(stack_a, stack_b, bench);
		else
		{
			if (biggest(stack_b)->current_i <= stacksize(*stack_b) / 2)
				rb(stack_b, bench);
			else
				rrb(stack_b, bench);
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
