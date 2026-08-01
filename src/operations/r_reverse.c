/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:16:12 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_values(t_node **stack)
{
	t_node	*temp;
	t_node	*penultimate;
	t_node	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = find_tail(*stack);
	temp = tail;
	penultimate = second_last(*stack);
	penultimate->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	rra(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	reverse_values(&push_swap->stack_a);
	count_op(push_swap, OP_RRA);
}

void	rrb(t_push_swap *push_swap)
{
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	reverse_values(&push_swap->stack_b);
	count_op(push_swap, OP_RRB);
}

void	rrr(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	reverse_values(&push_swap->stack_a);
	reverse_values(&push_swap->stack_b);
	count_op(push_swap, OP_RRR);
}
