/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_config.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:29:07 by mpeskov           #+#    #+#             */
/*   Updated: 2026/01/21 16:35:35 by mpeskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config	*init_config(void)
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config *));
	config->bench = 0;
	return (config);
}
