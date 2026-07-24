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
#include <limits.h>

static int	count_vnumber(char *str)
{
	int	i;
	int	start;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]))
		while (str[i] == '0')
			i++;
	else
		return (0);
	start = i;
	while (str[i])
		i++;
	return (i - start);
}

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
	while (stack != NULL)
	{
		if (stack->value == temp_num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_flag(char *str)
{
	int		i;
	char	*flags[6];

	i = 0;
	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
	flags[4] = "--bench";
	flags[5] = NULL;

	while (flags[i])
	{
		if (ft_strlen(str) == ft_strlen(flags[i])
		&& ft_strncmp(str, flags[i], ft_strlen(str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_int_range(char *str)
{
	long long	nmbr;
	int			digits;

	digits = count_vnumber(str);
	if (digits > 10)
		return (0);
	nmbr = ft_atol(str);
	if (nmbr > INT_MAX || nmbr < INT_MIN)
		return (0);
	return (1);
}
