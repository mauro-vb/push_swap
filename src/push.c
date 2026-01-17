/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:09:19 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/17 17:13:53 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the 
// top of a stack and put it at the top of other stack

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack *moving;
	t_stack	*src_tail;
	t_stack	*dest_tail;

	if (!(*stack_src))
		return ;
	moving = *stack_src;
	if (moving == moving->next)
		*stack_src = NULL;
	else
	{
		src_tail = moving->previous;
		(*stack_src) = moving->next;
		(*stack_src)->previous = src_tail;
		src_tail->next = *stack_src;
	}
	if (!*stack_dest)
	{
		*stack_dest = moving;
		moving->next = moving;
		moving->previous = moving;
	}
	else
	{
		dest_tail = (*stack_dest)->previous;
		moving->next = *stack_dest;
		moving->previous = dest_tail;
		(*stack_dest)->previous = moving;
		dest_tail->next = moving;
		*stack_dest = moving;
	}
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b)
		return (0);
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a)
		return (0);
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return (1);
}
