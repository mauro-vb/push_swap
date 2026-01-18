/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:07:40 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/18 17:28:40 by mvazquez         ###   ########.fr       */
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
	current_index_stack(stack);
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!swap(stack_a))
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!swap(stack_b))
		return (0);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stacksize(*stack_a) < 2 || stacksize(*stack_b) < 2)
		return (0);
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (1);
}
