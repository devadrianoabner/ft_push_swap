/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:59:37 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:18 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_simple_sort(int *values, int n)
{
	t_push_swap	*push_swap;

	push_swap = build_dummy_stack(values, n, NULL, 0);
	printf("=== ANTES ===\n");
	print_stack(push_swap->stack_a);
	complex_sort(push_swap);
	printf("=== DEPOIS ===\n");
	print_stack(push_swap->stack_a);
	if (is_sorted(push_swap->stack_a))
		printf("\nRESULTADO: OK, esta ordenado\n");
	else
		printf("\nRESULTADO: FALHOU, NAO esta ordenado\n");
	printf("stack_b deveria estar vazia: %s\n",
		push_swap->stack_b ? "NAO ESTA (bug)" : "esta vazia (ok)");
	free_stack(push_swap->stack_a);
	free_stack(push_swap->stack_b);
	free(push_swap);
}

int	main(void)
{
	int	values[12];

	values[0] = 5;
	values[1] = 1;
	values[2] = 9;
	values[3] = 3;
	values[4] = 7;
	values[5] = 2;
	values[6] = 8;
	values[7] = 4;
	values[8] = 6;
	values[9] = 12;
	values[10] = 10;
	values[11] = 11;
	test_simple_sort(values, 12);
	return (0);
}
/*
	test_one("sa", sa);
	test_one("sb", sb);
	test_one("ss", ss);
	test_one("pa", pa);
	test_one("pb", pb);
	test_one("ra", ra);
	test_one("rb", rb);
	test_one("rr", rr);
	test_one("rra", rra);
	test_one("rrb", rrb);
	test_one("rrr", rrr);
	values_a[0] = 0;
	values_a[1] = 1;
	values_a[2] = 2;
	values_a[3] = 3;
	values_a[4] = 4;
	values_b[0] = 5;
	values_b[1] = 6;
	values_b[2] = 7;
	values_b[3] = 8;
	values_b[4] = 9;
*/