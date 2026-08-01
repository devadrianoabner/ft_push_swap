/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:02:38 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/01 17:08:25 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
