/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:13:09 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/08 15:21:09 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sort_three(t_push_swap *push_swap)
{
	t_node	*highest_node;

	highest_node = get_node(push_swap->stack_a, GET_MAX);
	if (push_swap->stack_a == highest_node)
		ra(push_swap);
	else if (push_swap->stack_a->next == highest_node)
		rra(push_swap);
	if (push_swap->stack_a->value > push_swap->stack_a->next->value)
		sa(push_swap);
}