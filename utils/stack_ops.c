/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:53:19 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/12 13:51:34 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements at the top of stack sa, sb, ss
int	swap(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*snd;
	int		tmp_val;

	if (stacksize(*stack) < 2)
		return (0);
	fst = *stack;
	snd = fst->next;
	if (!fst || !snd)
		return (0);
	tmp_val = fst->value;
	fst->value = snd->value;
	snd->value = tmp_val;
	return (1);
}

// Take the first element at the top of a stack and put it at the top of other stack
int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*fst_to;
	t_stack	*fst_from;
	int		tmp_val;

	if (!stack_to || !stack_from)
		return (0);
	fst_to = *stack_to;
	fst_from = *stack_from;
	if (!fst_to || !fst_from)
		return (0);
	tmp_val = fst_to->value;
	fst_to->value = fst_from->value;
	fst_from->value = tmp_val;
	return (1);
}

// Shift up all elements of stack by one. 
// If reverse the last element becomes the first one.
// Else the first element becomes the last one.
int	rotate(t_stack **stack, int reverse)
{
	t_stack	*fst;
	t_stack	*last;
	
	if (!stack)
		return (0);
	fst = *stack;
	last = stacklast(*stack);
	if (!last || !fst)
		return (0);
	if (reverse)
	{
		stackadd_front(stack, stacknew(last->value));
		stackdelone(last);
		//*stack = fst->previous;
	}
	else
	{
		stackadd_back(stack, stacknew(fst->value));
		stackdelone(fst);
		*stack = fst->next;
	}
	return (1);
}
