/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:09:51 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/22 12:06:14 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_free(t_stack *head)
{
	t_stack	*tmp;

	if (head == NULL)
		return ;
	if (head->next == head)
	{
		free(head);
		return ;
	}
	tmp = head->next;
	head->next = head->next->next;
	free(tmp);
	recursive_free(head);
}

void	free_all(t_stack *a, t_stack *b, t_config *config)
{
	recursive_free(a);
	recursive_free(b);
	free(config);
}

void	free_split(char **strs)
{
	size_t	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
