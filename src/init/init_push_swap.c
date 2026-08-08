/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:27:33 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/07 18:17:15 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(t_push_swap *push_swap)
{
	int	i;

	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->bench = 0;
	push_swap->disorder = 0.0;
	push_swap->strategy = FLAG_ADAPTIVE;
	push_swap->strategy_selected = FLAG_NONE;
	i = 0;
	while (i < OP_TYPES_TOTAL)
	{
		push_swap->op_counts[i] = 0;
		i++;
	}
}
