/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:24 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 20:59:49 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *push_swap)
{
	// armazenar topo de stack_b em um temp
	// stack_b apontará para o próximo nó
	// já a stack_a vai apontar para o temp
	// o temp vai apontar para o topo da stack_a
	t_node *top_a;
	t_node *top_b;
	t_node *temp;

	top_a = push_swap->stack_a;
	top_b = push_swap->stack_b;	
	temp = top_b->next;
	top_b = temp->next;
	top_b->next = top_a->next;
	top_a = top_b;
}

void	pb(t_push_swap *push_swap)
{
	(void)push_swap;
}
