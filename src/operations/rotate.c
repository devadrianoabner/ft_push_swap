/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:55 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/24 15:08:09 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *push_swap)
{
	t_node *moved;

	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	moved = push_swap->stack_a;
	push_swap->tail_a->next = moved;
	push_swap->stack_a = push_swap->stack_a->next;
	moved->next = NULL;
	push_swap->tail_a = moved;
}

void	rb(t_push_swap *push_swap)
{
	t_node *moved;

	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	moved = push_swap->stack_b;
	push_swap->tail_b->next = moved;
	push_swap->stack_b = push_swap->stack_b->next;
	moved->next = NULL;
	push_swap->tail_b = moved;
}

void	rr(t_push_swap *push_swap)
{
	ra(push_swap);
	rb(push_swap);
}
