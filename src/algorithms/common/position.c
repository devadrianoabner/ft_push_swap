/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:51 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/08 15:21:12 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_node	*get_target_node(t_node *stack_a, t_node *stack_b)
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


t_node  *get_target_for_b(t_node *stack_a, t_node *node_b)
{
    t_node  *current_a;
    t_node  *target_node;
    long    min_bigger;

    min_bigger = LONG_MAX;
    target_node = NULL;
    current_a = stack_a;
    while (current_a)
    {
        if (current_a->value > node_b->value && current_a->value < min_bigger)
        {
            min_bigger = current_a->value;
            target_node = current_a;
        }
        current_a = current_a->next;
    }
    if (target_node != NULL)
        return (target_node);
    return (get_node(stack_a, GET_MIN));
}
