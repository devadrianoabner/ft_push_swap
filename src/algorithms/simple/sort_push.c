/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:44 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:59:39 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "simple.h"
#include "common.h"

void	get_cheapest_move(t_push_swap *push_swap, t_move *best_move)
{
	t_node	*current_a;
	t_move	current_move;

	best_move->total_cost = INT_MAX;
	current_a = push_swap->stack_a;
	while (current_a)
	{
		current_move.node_a = current_a;
		current_move.target_b = get_target_node(current_a, push_swap->stack_b);
		calculate_cost(push_swap->stack_a, push_swap->stack_b, &current_move);
		optimize_total_cost(&current_move);
		if (current_move.total_cost < best_move->total_cost)
			*best_move = current_move;
		current_a = current_a->next;
	}
}


void	push_cheapest_to_b(t_push_swap *push_swap)
{
    t_move	best_move;

	get_cheapest_move(push_swap, &best_move);
	apply_moves(push_swap, &best_move);
}

