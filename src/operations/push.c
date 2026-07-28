/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/28 15:08:36 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_values(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

static void	tails_checker(t_node *head, t_node **tail)
{
	if (!head)
		*tail = NULL;
	else if (!head->next)
		*tail = head;
}

void	pa(t_push_swap *push_swap)
{
	if (!push_swap->stack_b)
		return ;
	push_values(&push_swap->stack_b, &push_swap->stack_a);
	tails_checker(push_swap->stack_b, &push_swap->tail_b);
	tails_checker(push_swap->stack_a, &push_swap->tail_a);
	count_op(push_swap, OP_PA);
	count_op(push_swap, OP_TYPES_TOTAL);
}

void	pb(t_push_swap *push_swap)
{
	if (!push_swap->stack_a)
		return ;
	push_values(&push_swap->stack_a, &push_swap->stack_b);
	tails_checker(push_swap->stack_a, &push_swap->tail_a);
	tails_checker(push_swap->stack_b, &push_swap->tail_b);
	count_op(push_swap, OP_PB);
	count_op(push_swap, OP_TYPES_TOTAL);
}
