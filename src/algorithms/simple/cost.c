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

static void	set_cost_a(t_node *stack_a, t_move *move)
{
	int	size_a;
	int	index_a;

	size_a = stack_size(stack_a);
	index_a = get_index(stack_a, move->node_a);
	move->cost_a = get_single_cost(size_a, index_a);
}


static void	set_cost_b(t_node *stack_b, t_move *move)
{
	int	size_b;
	int	index_b;

	if (!stack_b || !move->target_b)
	{
		move->cost_b = 0;
		return ;
	}
	size_b = stack_size(stack_b);
	index_b = get_index(stack_b, move->target_b);
	move->cost_b = get_single_cost(size_b, index_b);
}


void	calculate_cost(t_node *stack_a, t_node *stack_b, t_move *move)
{
	set_cost_a(stack_a, move);
	set_cost_b(stack_b, move);
}


void	optimize_total_cost(t_move *move)
{
	int	cost_a;
	int cost_b;

	cost_a = move->cost_a;
	cost_b = move->cost_b;
	if (cost_a < 0)
        cost_a = cost_a * -1;
    if (cost_b < 0)
        cost_b = cost_b * -1;
	if ((move->cost_a > 0 && move->cost_b > 0)
		|| (move->cost_a < 0 && move->cost_b < 0))
	{
		if (cost_a >= cost_b)
			move->total_cost = cost_a;
		else
			move->total_cost = cost_b;
	}
	else
		move->total_cost = cost_a + cost_b;
}
