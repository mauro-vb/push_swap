/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:14:52 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/22 11:04:50 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*i;
	t_stack	*j;

	if (!stack || stacksize(stack) < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i->next != stack)
	{
		j = i->next;
		while (j != stack)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((int)(((float)mistakes / (float)total_pairs) * 10000.0));
}
