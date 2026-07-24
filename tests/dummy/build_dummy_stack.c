/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dummy_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:10:01 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/24 16:44:48 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

static t_node	*create_node(int value)
{
	t_node	*new;

	new = ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

static void	insert_node(t_node **stack, t_node **tail, t_node *new)
{
	if (!*stack)
	{
		*stack = new;
		*tail = new;
		return ;
	}
	(*tail)->next = new;
	*tail = new;
}

static void	fill_stack(t_node **stack, t_node **tail, int *values, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		insert_node(stack, tail, create_node(values[i]));
		i++;
	}
}

t_push_swap	*build_dummy_stack(int *values_a, int n_a, int *values_b, int n_b)
{
	t_push_swap	*push_swap;

	push_swap = ft_calloc(sizeof(t_push_swap), 1);
	if (!push_swap)
		return (NULL);
	fill_stack(&push_swap->stack_a, &push_swap->tail_a, values_a, n_a);
	fill_stack(&push_swap->stack_b, &push_swap->tail_b, values_b, n_b);
	return (push_swap);
}
