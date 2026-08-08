/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:53:27 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:18:19 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}


int	is_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL && node_compare(stack, stack->next))
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}


t_node	*find_tail(t_node *stack)
{
	t_node	*tail;

	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	tail = stack;
	return (tail);
}


int	get_index(t_node *stack, t_node *node)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stack;
	while (current != NULL)
	{
		if (current == node)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	get_rank(t_push_swap *push_swap, t_node *node)
{
	int	rank;
	t_node *current;

	rank = 0;
	current = push_swap->stack_a;
	while (current != NULL)
	{
		if (node->value > current->value)
			rank++;
		current = current->next;
	}
	if (!push_swap->stack_b)
		return (rank);
	current = push_swap->stack_b;
	while (current != NULL)
	{
		if (node->value > current->value)
			rank++;
		current = current->next;
	}
	return (rank);
}