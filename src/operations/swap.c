/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:59 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/27 15:10:47 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_values(t_node **stack, t_node **tail)
{
	t_node	*src;
	t_node	*dest;

	if (!*stack || !(*stack)->next)
		return ;
	src = *stack;
	dest = (*stack)->next;
	src->next = dest->next;
	dest->next = src;
	*stack = dest;
	if (!src->next)
		*tail = src;
}

void	sa(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	swap_values(&push_swap->stack_a, &push_swap->tail_a);
	count_op(push_swap, OP_SA);
}

void	sb(t_push_swap *push_swap)
{
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	swap_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_SB);
}

void	ss(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	swap_values(&push_swap->stack_a, &push_swap->tail_a);
	swap_values(&push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_SS);
}
