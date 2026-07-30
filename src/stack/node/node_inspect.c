/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_inspect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:31:36 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/30 20:07:18 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node *find_max_node(t_node *stack)
{
	t_node *max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while(stack != NULL)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static	t_node *find_min_node(t_node *stack)
{
	t_node *min_node;

	if (!stack)
	return (NULL);
	min_node = stack;
	while (stack != NULL)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next; 
	}
	return (min_node);
}

int	node_compare(t_node *src, t_node *dest)
{
	return (src->value < dest->value);
}

t_node	*second_last(t_node *stack)
{
	if (!stack || stack->next == NULL)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}


t_node	*get_node(t_node *stack, int type)
{
	t_node *result;
	if (!stack)
		return (NULL);
	if (type == GET_MIN)
		return (find_min_node(stack));
	else if (type == GET_MAX)
		return (find_min_max(stack));
	return (NULL);
}
