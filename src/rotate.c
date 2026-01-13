/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:12:07 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/13 16:45:53 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack by one. 
// If reverse the last element becomes the first one.
// Else the first element becomes the last one.

static int	rotate(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*last;
	
	if (!stack)
		return (0);
	fst = *stack;
	last = stacklast(*stack);
	if (!fst || !last)
		return (0);
	*stack = fst->next;
	(*stack)->previous = NULL;
	fst->next = NULL;
	fst->previous = last;
	last->next = fst;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!rotate(stack_a))
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (!rotate(stack_b))
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rotate(stack_a) || !rotate(stack_b))
		return (0);
	ft_printf("rr\n");
	return (1);
}
