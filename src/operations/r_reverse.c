/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/24 15:42:40 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *push_swap)
{
	t_node *temp;
	t_node *penultimate;

	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	temp = push_swap->tail_a;
	penultimate = second_last(push_swap->stack_a);
	penultimate->next = NULL;
	temp->next = push_swap->stack_a;
	push_swap->stack_a = temp;
	push_swap->tail_a = penultimate;
}

void	rrb(t_push_swap *push_swap)
{
	t_node *temp;
	t_node *penultimate;

	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	temp = push_swap->tail_b;
	penultimate = second_last(push_swap->stack_b);
	penultimate->next = NULL;
	temp->next = push_swap->stack_b;
	push_swap->stack_b = temp;
	push_swap->tail_b = penultimate;
}

void	rrr(t_push_swap *push_swap)
{
	rra(push_swap);
	rrb(push_swap);
}
