/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:12:07 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 15:03:14 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack by one. 
// If reverse the last element becomes the first one.
// Else the first element becomes the last one.

static void	rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
	{
		return ;
	}
	*stack = (*stack)->next;
}

int	ra(t_stack **stack_a, t_bench *bench)
{
	rotate(stack_a);
	ft_printf("ra\n");
	bench->ra++;
	return (1);
}

int	rb(t_stack **stack_b, t_bench *bench)
{
	rotate(stack_b);
	ft_printf("rb\n");
	bench->rb++;
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	bench->rr++;
	return (1);
}
