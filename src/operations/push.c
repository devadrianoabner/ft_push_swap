/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:44:08 by adrianda         ###   ########.fr       */
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

void	pa(t_push_swap *push_swap)
{
	if (!push_swap->stack_b)
		return ;
	push_values(&push_swap->stack_b, &push_swap->stack_a);
	count_op(push_swap, OP_PA);
}

void	pb(t_push_swap *push_swap)
{
	if (!push_swap->stack_a)
		return ;
	push_values(&push_swap->stack_a, &push_swap->stack_b);
	count_op(push_swap, OP_PB);
}
