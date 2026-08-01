/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:53:27 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 17:18:40 by adrianda         ###   ########.fr       */
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

int	is_empty(t_node *stack)
{
	return (stack == NULL);
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