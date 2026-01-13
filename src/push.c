/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:09:19 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/13 15:58:48 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the 
// top of a stack and put it at the top of other stack

static int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;

	if (!stack_from || !*stack_from)
		return (0);
	tmp = *stack_from;
	*stack_from = tmp->next;
	if (*stack_from)
		(*stack_from)->previous = NULL;
	tmp->next = *stack_to;
	tmp->previous = NULL;
	if (*stack_to)
		(*stack_to)->previous = tmp;
	*stack_to = tmp;
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_a, stack_b))
		return (0);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!push(stack_b, stack_a))
		return (0);
	ft_printf("pb\n");
	return (1);
}
