/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:05 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 16:48:49 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **argv, int argc)
{
	char	**args;
	char	**split_ptr;
	t_stack	*head;

	if (argc == 2)
		args = ft_split(get_input_str(argv), " ");
	else
		args = argv + 1;
	while (*args[0] == '\0')
		args++;
	head = stacknew(ft_atoi(*args));
	split_ptr = args;
	args++;
	while (args[i++])
	{
		if (args[i][0] != '\0')
			stackadd_back(&head, stacknew(ft_atoi(args[i])));
	}
	index_stack(&head);
	current_index_stack(&head);
	if (argc == 2)
		free_split(split_ptr);
	return (head);
}
