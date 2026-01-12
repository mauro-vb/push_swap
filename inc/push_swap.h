/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:08 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/12 11:33:25 by mvazquez         ###   ########.fr       */
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
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);

float	compute_disorder(t_stack *stack);

#endif
