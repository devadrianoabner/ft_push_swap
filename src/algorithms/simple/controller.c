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
#include "simple.h"

// nova função
void    final_alignment(t_push_swap *push_swap)
{
    t_node  *min_node;

    min_node = get_node(push_swap->stack_a, GET_MIN);
    if (!min_node)
        return ;
    rotate_stack_a(push_swap, min_node);
}

void	greedy_sort(t_push_swap *push_swap)
{
	// lembrar de remover
	while (stack_size(push_swap->stack_a) > 3)
	{
		push_cheapest_to_b(push_swap);
	}
	sort_three(push_swap);
	push_all_to_a(push_swap);
	final_alignment(push_swap);
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
