/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dummy_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:10:01 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 14:24:08 by adrianda         ###   ########.fr       */
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

static void	insert_node(t_push_swap *push_swap, t_node *new)
{
	if (!push_swap->stack_a)
	{
		push_swap->stack_a = new;
		push_swap->tail_a = new;
		new->index = 0;
		return ;
	}
	push_swap->tail_a->next = new;
	new->index = push_swap->tail_a->index + 1;
	push_swap->tail_a = new;
}

t_push_swap	*build_dummy_stack(int *values, int n)
{
	t_push_swap	*push_swap;
	int			i;

	push_swap = ft_calloc(sizeof(t_push_swap), 1);
	if (!push_swap)
		return (NULL);
	i = 0;
	while (i < n)
	{
		insert_node(push_swap, create_node(values[i]));
		i++;
	}
	return (push_swap);
}
