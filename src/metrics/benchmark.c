/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:27:35 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/07 21:55:41 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_op(t_push_swap *push_swap)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < OP_TYPES_TOTAL)
	{
		total = total + push_swap->op_counts[i];
		i++;
	}
	return (total);
}

static void	print_disorder(t_push_swap *push_swap)
{
	int	scaled;
	
	scaled = (int)(push_swap->disorder * 10000 + 0.5);
	
	ft_putnbr_fd(scaled / 100, 2);
	ft_putchar_fd('.', 2);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(scaled % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	write_strategy(t_push_swap *push_swap)
{
	if (push_swap->strategy == FLAG_SIMPLE)
		ft_putstr_fd("Simple /", 2);
	else if (push_swap->strategy == FLAG_MEDIUM)
		ft_putstr_fd("Medium /", 2);
	else if (push_swap->strategy == FLAG_COMPLEX)
		ft_putstr_fd("Complex /", 2);
	else if (push_swap->strategy == FLAG_ADAPTIVE)
		ft_putstr_fd("Adaptive /", 2);
}

static void	write_formula(t_push_swap *push_swap)
{
	if (push_swap->strategy_selected == FLAG_SIMPLE)
		ft_putstr_fd(" O(n^2)\n", 2);
	else if (push_swap->strategy_selected == FLAG_MEDIUM)
		ft_putstr_fd(" O(n√n)\n", 2);
	else if (push_swap->strategy_selected == FLAG_COMPLEX)
		ft_putstr_fd(" O(n log n)\n", 2);
}

void	benchmark(t_push_swap *push_swap)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(push_swap);
	ft_putstr_fd("[bench] strategy: ", 2);
	write_strategy(push_swap);
	write_formula(push_swap);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_op(push_swap), 2);
	ft_putchar_fd('\n', 2);
	print_op_counts(push_swap);
}

