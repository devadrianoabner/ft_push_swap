/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:01:11 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/01 17:11:18 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup_push_swap(t_push_swap *push_swap)
{
	if (!push_swap)
		return ;
	free_stack(push_swap->stack_a);
	free_stack(push_swap->stack_b);
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->tail_a = NULL;
	push_swap->tail_b = NULL;
}

int	handle_error(t_push_swap *push_swap)
{
	cleanup_push_swap(push_swap);
	write(2, "Error\n", 6);
	return (1);
}
