/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inspect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:53:27 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 19:37:28 by adrianda         ###   ########.fr       */
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

t_node *second_last(t_node *stack)
{
	if (!stack || stack->next == NULL)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
