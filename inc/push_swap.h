/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:08 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/15 13:16:26 by mpeskov          ###   ########.fr       */
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
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);
size_t	stacksize(t_stack *head);
void	index_stack(t_stack **stack);
int		is_sorted(t_stack *stack)

float	compute_disorder(t_stack *stack);

// instructions

int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack **stack_a, t_stack **stack_b);

int	pa(t_stack **stack_a, t_stack **stack_b);
int	pb(t_stack **stack_a, t_stack **stack_b);

int	ra(t_stack **stack_a);
int	rb(t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);

int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);

//simple sort

void	bubble_sort(t_stack	**stack);
#endif
