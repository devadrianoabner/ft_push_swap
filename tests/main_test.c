/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:59:37 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/27 17:34:07 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_both(t_push_swap *push_swap)
{
	printf("stack_a:\n");
	print_stack(push_swap->stack_a);
	printf("stack_b:\n");
	print_stack(push_swap->stack_b);
}

static void	test_one(char *op_name, void (*op)(t_push_swap *))
{
	int			values_a[0];
	int			values_b[0];
	t_push_swap	*push_swap;


	push_swap = build_dummy_stack(values_a, 0, values_b, 0);
	
	printf("=== %s | ANTES ===\n", op_name);
	print_both(push_swap);
	op(push_swap);
	printf("=== %s | DEPOIS ===\n", op_name);
	print_both(push_swap);
	printf("\n");
	printf("%d",push_swap->op_counts);
	free_stack(push_swap->stack_a);
	free_stack(push_swap->stack_b);
	free(push_swap);
}

int	main(void)
{
	test_one("sb", sa);

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