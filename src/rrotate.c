/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:31:42 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/13 17:02:00 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack by one. 
// If reverse the last element becomes the first one.
// Else the first element becomes the last one.

static int	rrotate(t_stack **stack)
{
	t_stack	*fst;
	t_stack	*last;
	t_stack	*penultim;
	
	if (!stack)
		return (0);
	fst = *stack;
	last = stacklast(*stack);
	if (!fst || !last)
		return (0);
	penultim = last->previous;
	last->next = fst;
	last->previous = NULL;
	if (penultim)
		penultim->next = NULL;
	*stack = last;
	return (1);

}

int	rra(t_stack **stack_a)
{
	if (!rrotate(stack_a))
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (!rrotate(stack_b))
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rrotate(stack_a) || !rrotate(stack_b))
		return (0);
	ft_printf("rrr\n");
	return (1);
}
