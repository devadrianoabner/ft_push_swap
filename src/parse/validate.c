/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:45:03 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/16 19:46:05 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *str)
{
	int	i;
	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	has_duplicate(t_ps *push_swap, int temp_num)
{
	t_node	*stack;

	if (!push_swap->stack_a)
		return (0);
	stack = push_swap->stack_a;
	while(stack != NULL)
	{
		if (stack->value == temp_num)
			return (1);
		stack = stack->next;
	}
	return (0);
}


