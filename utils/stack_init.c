/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:05 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 17:58:16 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_stack *head, char **args)
{
	t_stack	*tmp;

	while (*args)
	{
		if (*args[0] != '\0')
		{
			tmp = stacknew(ft_atoi(*args));
			if (!tmp)
				return (recursive_free(head));
			stackadd_back(&head, tmp);
		}
		args++;
	}
}

t_stack	*init_stack(char **argv, int argc)
{
	char	**args;
	char	**split_ptr;
	t_stack	*head;

	if (argc == 2)
		args = ft_split(get_input_str(argv), " \n");
	else
		args = argv + 1;
	while (*args[0] == '\0')
		args++;
	head = stacknew(ft_atoi(*args));
	split_ptr = args;
	args++;
	add_node(head, argv);
	index_stack(&head);
	current_index_stack(&head);
	return (free_split(split_ptr), head);
}
