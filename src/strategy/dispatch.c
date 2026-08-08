/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:21:58 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/08 15:29:34 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive_strategy(t_push_swap *push_swap)
{
	if (push_swap->disorder < 0.2)
	{
		push_swap->strategy_selected = FLAG_SIMPLE;
		simple_sort(push_swap);
	}
	else if (push_swap->disorder < 0.5)
	{
		push_swap->strategy_selected = FLAG_MEDIUM;
		medium_sort(push_swap);
	}
	else
	{
		push_swap->strategy_selected = FLAG_COMPLEX;
		complex_sort(push_swap);
	}
}

void	dispatch_strategy(t_push_swap *push_swap)
{
	if (push_swap->strategy == FLAG_SIMPLE)
	{
		push_swap->strategy_selected = FLAG_SIMPLE;
		simple_sort(push_swap);
	}
 	else if (push_swap->strategy == FLAG_MEDIUM)
	{
		push_swap->strategy_selected = FLAG_MEDIUM;
		medium_sort(push_swap);
	}
	else if (push_swap->strategy == FLAG_COMPLEX)
	{
		push_swap->strategy_selected = FLAG_COMPLEX;
		complex_sort(push_swap);
	}
	else if (push_swap->strategy == FLAG_ADAPTIVE)
		adaptive_strategy(push_swap);
}
