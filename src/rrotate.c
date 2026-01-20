/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:31:42 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 15:03:20 by mvazquez         ###   ########.fr       */
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
}

int	rra(t_stack **stack_a, t_bench *bench)
{
	rrotate(stack_a);
	ft_printf("rra\n");
	bench->rra++;
	return (1);
}

int	rrb(t_stack **stack_b, t_bench *bench)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
	bench->rrb++;
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
	bench->rrr++;
	return (1);
}
