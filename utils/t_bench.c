/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bench.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:23:30 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/20 11:47:26 by mpeskov          ###   ########.fr       */
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
	return (bench);
}

void	print_bench(t_bench *bench)
{
	write
