/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:21:55 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:47:29 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	int		len_a;
	int		len_b;
	int		i;
	t_node	*current_a;
	t_node	*current_b;

	len_a = stack_size(stack_a);
	len_b = stack_size(stack_b);
	current_a = stack_a;
	current_b = stack_b;
	i = 0;
	while (current_a)
	{
		i++;
		current_a = current_a->next;
	}
}
