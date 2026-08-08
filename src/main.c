/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:38:48 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/08 15:22:12 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_push_swap	push_swap;

	init_push_swap(&push_swap);
	push_swap.disorder = 0.40;
	push_swap.strategy = FLAG_ADAPTIVE;
	push_swap.strategy_selected = FLAG_MEDIUM;
	push_swap.op_counts[OP_PA] = 5;
	push_swap.op_counts[OP_PB] = 5;
	push_swap.op_counts[OP_RA] = 2;
	push_swap.op_counts[OP_RB] = 1;
	benchmark(&push_swap);
	return (0);
}
