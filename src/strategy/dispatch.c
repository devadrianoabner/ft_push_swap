/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:21:58 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/06 17:51:33 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_strategy(t_push_swap *push_swap)
{
	
	if (push_swap->strategy == FLAG_SIMPLE)
		simple_sort(push_swap);
//devo retirar o comentário quando os algoritmos estiverem prontos.
//a lógica está certa (até então);
/* 	else if (push_swap->strategy == FLAG_MEDIUM)
		medium_sort(push_swap);
	else if (push_swap->strategy == FLAG_COMPLEX)
		complex_sort(push_swap);
	else if (push_swap->strategy == FLAG_ADAPTIVE)
	{
		if (push_swap->disorder < 0.2)
			simple_sort(push_swap);
		else if (push_swap->disorder < 0.5)
			medium_sort(push_swap);
		else
			complex_sort(push_swap);
	}*/
}