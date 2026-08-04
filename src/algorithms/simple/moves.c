/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:40 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 22:07:46 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "simple.h"

void	apply_moves(t_push_swap *push_swap, t_move *move)
{
	rotate_both(push_swap, move);
	rotate_a(push_swap, move);
	rotate_b(push_swap, move);
	pb(push_swap);
}


void	rotate_both(t_push_swap *push_swap, t_move *move)
{
	while (move->cost_a > 0 && move->cost_b > 0)
	{
		rr(push_swap);
		move->cost_a--;
		move->cost_b--;
	}
	while (move->cost_a < 0 && move->cost_b < 0)
	{
		rrr(push_swap);
		move->cost_a++;
		move->cost_b++;
	}
}


void	rotate_a(t_push_swap *push_swap, t_move *move)
{
	while (move->cost_a > 0)
	{
		ra(push_swap);
		move->cost_a--;
	}
	while (move->cost_a < 0)
	{
		rra(push_swap);
		move->cost_a++;
	}
}


void	rotate_b(t_push_swap *push_swap, t_move *move)
{
	while (move->cost_b > 0)
	{
		rb(push_swap);
		move->cost_b--;
	}
	while (move->cost_b < 0)
	{
		rrb(push_swap);
		move->cost_b++;
	}
}
