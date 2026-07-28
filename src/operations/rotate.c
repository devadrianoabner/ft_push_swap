/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:55 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/28 15:03:51 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_values(t_node **stack, t_node **tail)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	(*tail)->next = temp;
	*stack = (*stack)->next;
	temp->next = NULL;
	*tail = temp;
}

void	ra(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	rotate_values(&push_swap->stack_a, &push_swap->tail_a);
	count_op(push_swap, OP_RA);
}

void	rb(t_push_swap *push_swap)
{
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	rotate_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_RB);
}

void	rr(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	rotate_values(&push_swap->stack_a, &push_swap->tail_a);
	rotate_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_RR);
}
