/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:27:33 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/01 18:34:24 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_push_swap *push_swap)
{
	int	i;

	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->bench = 0;
	push_swap->strategy = FLAG_ADAPTIVE;
	i = 0;
	while (i < OP_TYPES_TOTAL)
	{
		push_swap->op_counts[i] = 0;
		i++;
	}
}
