/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:09:19 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 15:08:56 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the 
// top of a stack and put it at the top of other stack

static void	handle_dest(t_stack	**stack_dest, t_stack *moving)
{
	t_stack	*dest_tail;

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

static void	handle_src(t_stack **stack_src, t_stack *moving)
{
	t_stack	*src_tail;

	if (moving == moving->next)
		*stack_src = NULL;
	else
	{
		src_tail = moving->previous;
		(*stack_src) = moving->next;
		(*stack_src)->previous = src_tail;
		src_tail->next = *stack_src;
	}
}

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*moving;

	if (!(*stack_src))
		return ;
	moving = *stack_src;
	handle_src(stack_src, moving);
	handle_dest(stack_dest, moving);
}

int	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (!stack_b)
		return (0);
	push(stack_a, stack_b);
	ft_printf("pa\n");
	bench->pa++;
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (!stack_a)
		return (0);
	push(stack_b, stack_a);
	ft_printf("pb\n");
	bench->pb++;
	return (1);
}
