/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:55 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:17:19 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_values(t_node **stack)
{
	t_node	*temp;
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = find_tail(*stack);
	temp = *stack;
	tail->next = temp;
	*stack = (*stack)->next;
	temp->next = NULL;
}

void	ra(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	rotate_values(&push_swap->stack_a);
	count_op(push_swap, OP_RA);
}

void	rb(t_push_swap *push_swap)
{
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	rotate_values(&push_swap->stack_b);
	count_op(push_swap, OP_RB);
}

void	rr(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	rotate_values(&push_swap->stack_a);
	rotate_values(&push_swap->stack_b);
	count_op(push_swap, OP_RR);
}
