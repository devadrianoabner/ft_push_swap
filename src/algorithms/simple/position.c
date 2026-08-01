/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:47:37 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_target_position(t_node *stack_a, t_node *stack_b)
{
	t_node		*current_b;
	t_node		*target_node;
	long long	value;

	value = LONG_MIN;
	current_b = stack_b;
	target_node = NULL;
	while (current_b)
	{
		if (current_b->value < stack_a->value && current_b->value > value)
		{
			value = current_b->value;
			target_node = current_b;
		}
		current_b = current_b->next;
	}
	if (target_node != NULL)
		return (target_node);
	return (get_node(stack_b, GET_MAX));
}
