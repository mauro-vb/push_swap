/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bench.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:23:30 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/20 12:16:43 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	init_bench(char	*strat, float disorder);
{
	t_bench	bench;

	bench.disorder = disorder;
	bench.strat = ft_strdup(strat);
	bench.sa = 0;
	bench.sb = 0;
	bench.ss = 0;
	bench.pb = 0;
	bench.pa = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	bench.total = 0;
	return (bench);
}

void print_first_bench_line(t_bench *bench)
{
	write(2, "[bench] sa: ", 12);
	write(2, ft_itoa(bench->sa), ft_strlen(ft_itoa(bench->sa)));
	write(2, " sb: ", 5);
	write(2, ft_itoa(bench->sb), ft_strlen(ft_itoa(bench->sb)));
	write(2, " ss: ", 5);
	write(2, ft_itoa(bench->ss), ft_strlen(ft_itoa(bench->ss)));
	write(2, " pa: ", 5);
	write(2, ft_itoa(bench->pa), ft_strlen(ft_itoa(bench->pa)));
	write(2, " pb: ", 5);
	write(2, ft_itoa(bench->pb), ft_strlen(ft_itoa(bench->pb)));
	write(2, "\n", 1);
}

void print_last_bench_line(t_bench *bench);
{
	write(2, "[bench] ra: ", 12);
	write(2, ft_itoa(bench->ra), ft_strlen(ft_itoa(bench->ra)));
	write(2, " rb: ", 5);
	write(2, ft_itoa(bench->rb), ft_strlen(ft_itoa(bench->rb)));
	write(2, " rr: ", 5);
	write(2, ft_itoa(bench->rr), ft_strlen(ft_itoa(bench->rr)));
	write(2, " rra: ", 6);
	write(2, ft_itoa(bench->rra), ft_strlen(ft_itoa(bench->rra)));
	write(2, " rrb: ", 6);
	write(2, ft_itoa(bench->rrb), ft_strlen(ft_itoa(bench->rrb)));
	write(2, " rrr: ", 6);
	write(2, ft_itoa(bench->rrr), ft_strlen(ft_itoa(bench->rrr)));
	write(2, "\n", 1);
}



void	print_bench(t_bench *bench)
{
	write(2, "[bench] disorder:\n", 18);
	write(2, "[bench] strategy: ", 18);
	write(2, bench->strat, ft_strlen(bench->strat));
	write(2, "\n", 1);
	write(2, "[bench] total ops: ", 19);
	write(2, ft_itoa(bench->total), ft_strlen(ft_itoa(bench->total));
	write(2, "\n", 1);
	print_first_bench_line(bench);
	print_last_bench_line(bench);
}
