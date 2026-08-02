/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:21:55 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:54:31 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "simple.h"

void	calculate_cost(t_node *stack_a, t_node *stack_b, t_move *move)
{
	int	size_a;
	int	index_a;

	size_a = stack_size(stack_a);
	index_a = get_index(stack_a, move->node_a);
	if (index_a <= size_a / 2)
		move->cost_a = index_a;
	else
		move->cost_a = (size_a - index_a) * -1;
}

//int	get_single_cost(int size, int index);
//void	optimize_total_cost(t_move *move);