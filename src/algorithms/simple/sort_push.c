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

// nova função
t_node  *get_target_for_b(t_node *stack_a, t_node *node_b)
{
    t_node  *current_a;
    t_node  *target_node;
    long    min_bigger;

    min_bigger = LONG_MAX;
    target_node = NULL;
    current_a = stack_a;
    while (current_a)
    {
        if (current_a->value > node_b->value && current_a->value < min_bigger)
        {
            min_bigger = current_a->value;
            target_node = current_a;
        }
        current_a = current_a->next;
    }
    if (target_node != NULL)
        return (target_node);
    return (get_node(stack_a, GET_MIN));
}

void	push_cheapest_to_b(t_push_swap *push_swap)
{
    t_move	best_move;

	get_cheapest_move(push_swap, &best_move);
	apply_moves(push_swap, &best_move);
}

void	rotate_stack_a(t_push_swap *push_swap, t_node *target)
{
	t_move	move;
	int		size_a;
	int		index_a;

	size_a = stack_size(push_swap->stack_a);
	index_a = get_index(push_swap->stack_a, target);
	move.cost_a = get_single_cost(size_a, index_a);
	move.cost_b = 0;
	rotate_a(push_swap, &move);
}


void	push_all_to_a(t_push_swap *push_swap)
{
	t_node *target_node;

	while (push_swap->stack_b)
	{
		// lembrar de inverter a para b
		target_node = get_target_for_b(push_swap->stack_a, push_swap->stack_b);
		rotate_stack_a(push_swap, target_node);
		pa(push_swap);
	}
}