/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:07:40 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 15:03:06 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements at the top of stack sa, sb, ss

static int	swap(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*snd;
	int		tmp_val;
	int		tmp_index;

	if (stacksize(*stack) < 2)
		return (0);
	fst = *stack;
	snd = fst->next;
	if (!fst || !snd)
		return (0);
	tmp_val = fst->value;
	tmp_index = fst->index;
	fst->value = snd->value;
	fst->index = snd->index;
	snd->value = tmp_val;
	snd->index = tmp_index;
	return (1);
}

int	sa(t_stack **stack_a, t_bench *bench)
{
	if (!swap(stack_a))
		return (0);
	if (!bench->silent)
		ft_printf("sa\n");
	bench->sa++;
	return (1);
}

int	sb(t_stack **stack_b, t_bench *bench)
{
	if (!swap(stack_b))
		return (0);
	if (!bench->silent)
		ft_printf("sb\n");
	bench->sb++;
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (stacksize(*stack_a) < 2 || stacksize(*stack_b) < 2)
		return (0);
	swap(stack_a);
	swap(stack_b);
	if (!bench->silent)
		ft_printf("ss\n");
	bench->ss++;
	return (1);
}
