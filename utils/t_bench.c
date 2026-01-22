/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bench.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:23:30 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/22 12:00:13 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	init_bench(void)
{
	t_bench	bench;

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

static void	print_and_free(char *str, int val)
{
	char	*tmp;

	write(2, str, ft_strlen(str));
	tmp = ft_itoa(val);
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
}

static void	print_bench_line(t_bench *bench)
{
	print_and_free("[bench] sa: ", bench->sa);
	print_and_free(" sb: ", bench->sb);
	print_and_free(" ss: ", bench->ss);
	print_and_free(" pa: ", bench->pa);
	print_and_free(" pb: ", bench->pb);
	write(2, "\n", 1);
	print_and_free("[bench] ra: ", bench->ra);
	print_and_free(" rb: ", bench->rb);
	print_and_free(" rr: ", bench->rr);
	print_and_free(" rra: ", bench->rra);
	print_and_free(" rrb: ", bench->rrb);
	print_and_free(" rrr: ", bench->rrr);
	write(2, "\n", 1);
}

static char	*get_disorder(int disorder)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	if (disorder == 10000)
		return ("100.0");
	tmp = ft_itoa(disorder / 100);
	tmp2 = ft_strjoin(tmp, ".");
	free(tmp);
	tmp = ft_itoa(disorder % 100);
	res = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	return (res);
}

void	print_bench(t_bench *bench)
{
	char	*tmp;

	bench->total += bench->sa + bench->sb + bench->ss + bench->pa;
	bench->total += bench->pb + bench->rr + bench->ra + bench->rb;
	bench->total += bench->rra + bench->rrb + bench->rrr;
	write(2, "[bench] disorder: ", 18);
	tmp = get_disorder(bench->disorder);
	write(2, tmp, 5);
	free(tmp);
	write(2, "\n", 1);
	write(2, "[bench] strategy: ", 18);
	write(2, bench->strat, ft_strlen(bench->strat));
	write(2, "\n", 1);
	print_and_free("[bench] total ops: ", bench->total);
	write(2, "\n", 1);
	print_bench_line(bench);
}
