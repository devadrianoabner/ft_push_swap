/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:59 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 20:29:19 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *push_swap)
{
	int	temp;
	t_node *top_one;
	t_node *top_two;

	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	top_one = push_swap->stack_a;
	top_two = top_one->next;
	temp = push_swap->stack_a->value;
	top_one->value = top_two->value;
	top_two->value = temp;
}

void	sb(t_push_swap *push_swap)
{
	int	temp;
	t_node *top_one;
	t_node *top_two;

	if (!push_swap->stack_b || !push_swap->stack_b->next)
		return ;
	top_one = push_swap->stack_b;
	top_two = top_one->next;
	temp = push_swap->stack_b->value;
	top_one->value = top_two->value;
	top_two->value = temp;
}

void	ss(t_push_swap *push_swap)
{
	sa(push_swap);
	sb(push_swap);
}
