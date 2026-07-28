/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/28 15:03:43 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_values(t_node **stack, t_node **tail)
{
	t_node	*temp;
	t_node	*penultimate;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *tail;
	penultimate = second_last(*stack);
	penultimate->next = NULL;
	temp->next = *stack;
	*stack = temp;
	*tail = penultimate;
}

void	rra(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	reverse_values(&push_swap->stack_a, &push_swap->tail_a);
	count_op(push_swap, OP_RRA);
}

void	rrb(t_push_swap *push_swap)
{
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	reverse_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_RRB);
}

void	rrr(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	reverse_values(&push_swap->stack_a, &push_swap->tail_a);
	reverse_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_RRR);
}
