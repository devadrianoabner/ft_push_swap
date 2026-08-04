/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:35 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:36:41 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_sort(t_push_swap *push_swap)
{
	while (stack_size(push_swap->stack_a) > 3)
		push_cheapest_to_b(push_swap);
	sort_three(push_swap);
	push_all_to_a(push_swap);
}


void	simple_sort(t_push_swap *push_swap)
{
	int	size;

	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (is_sorted(push_swap->stack_a))
		return ;
	size = stack_size(push_swap->stack_a);
	if (size == 2)
	{
		if (push_swap->stack_a->value > push_swap->stack_a->next->value)
			sa(push_swap);
		return ;
	}
	if (size == 3)
		{
			sort_three(push_swap);
			return ;
		}
	greedy_sort(push_swap);
}
