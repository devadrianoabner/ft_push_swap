/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 21:22:18 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *push_swap)
{
	t_node	*moved;

	if (!push_swap->stack_a)
		return ;
	moved = push_swap->stack_b;
	push_swap->stack_b = push_swap->stack_b->next;
	moved->next = push_swap->stack_a;
	push_swap->stack_a = moved;
}

void	pb(t_push_swap *push_swap)
{
	t_node	*moved;

	if (!push_swap->stack_b)
		return ;
	moved = push_swap->stack_a;
	push_swap->stack_a = push_swap->stack_a->next;
	moved->next = push_swap->stack_b;
	push_swap->stack_b = moved;
}
