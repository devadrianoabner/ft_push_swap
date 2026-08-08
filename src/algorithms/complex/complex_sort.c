/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:13:29 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/08 15:20:50 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

static void	push_to_a(t_push_swap *push_swap)
{
	if (!push_swap->stack_b)
		return ;
	while (push_swap->stack_b)
		pa(push_swap);
}

static void	process_bit(t_push_swap *push_swap, int index, int stack_len)
{
	int	i;
	int	rank;

	i = 0;
	while (stack_len > i)
	{
		rank = get_rank(push_swap, push_swap->stack_a);
		if (((rank >> index) & 1) == 1)
			ra(push_swap);
		else
			pb(push_swap);
		i++;
	}
} 

static int	max_bit(int max_rank)
{
	int	i;

	i = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		i++;
	}
	return (i);
}


void	complex_sort(t_push_swap *push_swap)
{
	int	stack_len;
	int	bit_len;
	int	index;

	stack_len = stack_size(push_swap->stack_a);
	bit_len = max_bit(stack_len - 1);
	index = 0;
	while (bit_len > index)
	{
		if (is_sorted(push_swap->stack_a))
			return ;
		process_bit(push_swap, index, stack_len);
		push_to_a(push_swap);
		index++;
	}
}
