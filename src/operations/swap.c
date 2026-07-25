/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:59 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/25 15:20:14 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_values(t_node *stack)
{
	int		temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	sa(t_push_swap *push_swap)
{
	swap_values(push_swap->stack_a);
	count_op(push_swap, OP_SA);
}

void	sb(t_push_swap *push_swap)
{
	swap_values(push_swap->stack_b);
	count_op(push_swap, OP_SB);
}

void	ss(t_push_swap *push_swap)
{
	swap_values(push_swap->stack_a);
	swap_values(push_swap->stack_b);
	count_op(push_swap, OP_SS);
}
