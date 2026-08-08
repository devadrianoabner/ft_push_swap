/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 21:52:51 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/07 22:08:12 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op_counts(t_push_swap *push_swap)
{
	int		i;
	char	*op_names[OP_TYPES_TOTAL];

	op_names[0] = "sa";
	op_names[1] = "sb";
	op_names[2] = "ss";
	op_names[3] = "pa";
	op_names[4] = "pb";
	op_names[5] = "ra";
	op_names[6] = "rb";
	op_names[7] = "rr";
	op_names[8] = "rra";
	op_names[9] = "rrb";
	op_names[10] = "rrr";
	i = 0;
	ft_putstr_fd("[bench] ", 2);
	while (i < OP_TYPES_TOTAL)
	{
		ft_putstr_fd(op_names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(push_swap->op_counts[i], 2);
		if (i == OP_PB)
		{
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("[bench] ", 2);
		}
		else if (i != OP_PB && i != OP_RRR)
			ft_putchar_fd(' ', 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}