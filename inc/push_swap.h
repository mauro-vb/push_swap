/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:29:08 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/20 13:42:20 by mpeskov          ###   ########.fr       */
/*   Updated: 2026/01/15 13:16:26 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int			    value;
    long			index;
	size_t			current_i;
	size_t			totop_cost;
    struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*target_node;
}	t_stack;

typedef struct s_bench
{
	float	disorder;
	char	*strat;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}	t_bench;

typedef struct s_ops
{
	int (*swp)(t_stack **, t_bench*);
	int (*rot)(t_stack **, t_bench*);
	int (*rrot)(t_stack **, t_bench*);
}	t_ops;

typedef enum e_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_mode;

typedef struct s_config
{
	t_mode mode;
	int bench;
}	t_config;

// input handling and stack init

int	check_args(int argc, char **argv);
int	parse_flags(int argc, char **argv, t_config *config);
t_bench	init_bench(void);
void	print_bench(t_bench *bench);

// stack 

void	print_stack(t_stack *stack, int debug);
t_stack *stacknew(int value);
t_stack	*stacklast(t_stack *stack);
void	stackdelone(t_stack *stack);
void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);
size_t	stacksize(t_stack *head);
void	index_stack(t_stack **stack);
void	current_index_stack(t_stack **stack);
int		is_sorted(t_stack *stack);

float	compute_disorder(t_stack *stack);

// instructions

int	sa(t_stack **stack_a, t_bench *bench);
int	sb(t_stack **stack_b, t_bench *bench);
int	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

int	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

int	ra(t_stack **stack_a, t_bench *bench);
int	rb(t_stack **stack_b, t_bench *bench);
int	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

int	rra(t_stack **stack_a, t_bench *bench);
int	rrb(t_stack **stack_b, t_bench *bench);
int	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

// simple sort

void	selection_sort0(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	sort_three(t_stack **stack, int is_a, t_bench *bench);
void	turk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

// 
t_stack	*smallest(t_stack **stack_a);
t_stack	*biggest(t_stack **stack_a);
t_stack	*smallest_bigger(int value, t_stack **stack_a);
void	assign_target_node(t_stack **stack_a, t_stack **stack_b);
void	assign_totop_cost(t_stack **stack_a);

#endif
