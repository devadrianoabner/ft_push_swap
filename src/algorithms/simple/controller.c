/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:22:35 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:36:41 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	greedy_sort(t_push_swap *push_swap)
{
	if (stack_size(push_swap->stack_a) > 3)
		pb(push_swap);
	if (stack_size(push_swap->stack_a) > 3)
		pb(push_swap);
	while (stack_size(push_swap->stack_a) > 3)
	{
		// target, cost e moves -> ordenação dinâmica da pilha b de forma decrescente com movimentos entre pilha a e b
	}
	// chama a função que ordena os 3 itens na pilha a
	// devolve tudo para a pilha A (loop de pa)
}
//void	final_alignment(t_node **stack_a);

void	simple_sort(t_push_swap *push_swap)
{
	if (!push_swap->stack_a || !push_swap->stack_a->next)
		return ;
	if (is_sorted(push_swap->stack_a))
		return ;
	if (stack_size(push_swap->stack_a) <= 3)
		{
			// chamar função que ordena 3 itens na pilha a
			return ;
		}
	greedy_sort(push_swap);
}
