/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:39 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 13:43:32 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack, int is_a, t_bench *bench)
{
	int		head_val;
	int		tail_val;
	int		mid_val;
	t_ops	ops;

	if (is_a)
		ops = (t_ops){sa, ra, rra};
	else
		ops = (t_ops){sb, rb, rrb};
	if (stacksize(*stack) != 3)
		return ;
	head_val = (*stack)->index;
	tail_val = (*stack)->previous->index;
	mid_val = (*stack)->next->index;
	if (head_val > mid_val && mid_val > tail_val)
		return ;
	if (tail_val > head_val && tail_val > mid_val && head_val > mid_val)
		ops.swp(stack, bench);
	else if (head_val > tail_val && head_val > mid_val && mid_val < tail_val)
		ops.rot(stack, bench);
	else if (head_val > tail_val && head_val < mid_val && mid_val > tail_val)
		ops.rrot(stack, bench);
	else if (head_val > tail_val && head_val > mid_val && mid_val > tail_val)
	{
		ops.swp(stack, bench);
		ops.rrot(stack, bench);
	}
	else if (head_val < tail_val && head_val < mid_val && mid_val > tail_val)
	{
		ops.swp(stack, bench);
		ops.rot(stack, bench);
	}
}

