/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:59:37 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 14:05:02 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int			values[5];
	t_push_swap	*push_swap;

	values[0] = 5;
	values[1] = 2;
	values[2] = 9;
	values[3] = 1;
	values[4] = 6;
	push_swap = build_dummy_stack(values, 5);
	print_stack(push_swap->stack_a);
	free_stack(push_swap->stack_a);
	free(push_swap);
	return (0);
}
