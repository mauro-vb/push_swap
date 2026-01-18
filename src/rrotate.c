/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:31:42 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/18 17:28:16 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack by one. 
// If reverse the last element becomes the first one.
// Else the first element becomes the last one.

static void	rrotate(t_stack **stack)
{
	if (!(*stack) || (*stack)->previous == *stack)
		return ;
	*stack = (*stack)->previous;
	current_index_stack(stack);
}

int	rra(t_stack **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
	return (1);
}
