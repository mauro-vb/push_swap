/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:05 by mvazquez          #+#    #+#             */
/*   Updated: 2026/01/21 17:03:31 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **argv, int argc)
{
	char	**args;
	char	**split_ptr;
	t_stack	*head;
	t_stack	*tmp;
	int		i;

	if (argc == 2)
		args = ft_split(get_input_str(argv), " ");
	else
		args = argv + 1;
	while (*args[0] == '\0')
		args++;
	i = 0;
	head = stacknew(ft_atoi(*args));
	if (!head)
		return (NULL);
	split_ptr = args;
	args++;
	while (args[i++])
	{
		if (args[i][0] != '\0')
		{
			tmp = stacknew(ft_atoi(args[i]));
			if (!tmp)
				return (recursive_free(head), NULL);
			stackadd_back(&head, tmp);
		}
	}
	index_stack(&head);
	current_index_stack(&head);
	if (argc == 2)
		free_split(split_ptr);
	return (head);
}
