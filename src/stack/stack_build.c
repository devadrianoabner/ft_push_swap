/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:44:39 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:44:39 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	stack_a_add_back(t_push_swap *push_swap, int value)
{
	t_node	*new_node;
	t_node	*tail;

	if (push_swap == NULL)
		return (0);
	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (push_swap->stack_a == NULL)
		push_swap->stack_a = new_node;
	else
	{
		tail = find_tail(push_swap->stack_a);
		tail->next = new_node;
	}
	return (1);
}
