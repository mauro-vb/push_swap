/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:08 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/12 13:37:50 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int			    value;
    int             index;
    struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

t_stack *stacknew(int value);
t_stack	*stacklast(t_stack *stack);
void	stackdelone(t_stack *stack);
void	set_stack_indexes(t_stack *stack);
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);
size_t	stacksize(t_stack *head);

float	compute_disorder(t_stack *stack);
int		swap(t_stack **stack);
int		push(t_stack **stack_to, t_stack **stack_from);
int		rotate(t_stack **stack, int reverse);

#endif
