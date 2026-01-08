/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:14:52 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/08 15:43:23 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs
*/
#include "push_swap.h"

float   compute_disorder(t_stack *stack)
{
    int mistakes;
    int total_pairs;
	int	last_i;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	last_i = stacklast(stack)->index;
	i = 0;
	while (i <= last_i)
	{
		j = i + 1;
		while (j <= last_i)
		{
			total_pairs++;
			if (MAKE HELPER TO MAKE STACK INDEXABLE?)
		}
    }
}
