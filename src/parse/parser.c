/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:46:03 by rafcrist          #+#    #+#             */
/*   Updated: 2026/08/01 19:00:21 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	parse_number(char *str, t_push_swap *push_swap)
{
	int	n;

	if (!is_valid(str) || !is_int_range(str))
		return (0);
	n = ft_atol(str);
	if (has_duplicate(push_swap, n))
		return (0);
	if (!stack_a_add_back(push_swap, n))
		return (0);
	return (1);
}

static int	parse_group(char *argument, t_push_swap *push_swap)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(argument, ' ');
	if (splitted == NULL)
		return (0);
	if (splitted[0] == NULL)
	{
		free_split(splitted);
		return (0);
	}
	while (splitted[i])
	{
		if (!parse_number(splitted[i], push_swap))
		{
			free_split(splitted);
			return (0);
		}
		i++;
	}
	free_split(splitted);
	return (1);
}

static int	config_flags(t_push_swap *push_swap, int *strategy_seen,
		t_flag_id flag)
{
	if (flag == FLAG_BENCH)
	{
		if (push_swap->bench == 1)
			return (0);
		push_swap->bench = 1;
		return (1);
	}
	if (flag >= FLAG_SIMPLE && flag <= FLAG_ADAPTIVE)
	{
		if (*strategy_seen == 1)
			return (0);
		push_swap->strategy = flag;
		*strategy_seen = 1;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_push_swap *push_swap)
{
	int			i;
	int			strategy_seen;
	t_flag_id	flag;

	strategy_seen = 0;
	i = 1;
	while (i < argc)
	{
		flag = get_flag_code(argv[i]);
		if (flag != FLAG_NONE)
		{
			if (!config_flags(push_swap, &strategy_seen, flag))
				return (0);
		}
		else
		{
			if (!parse_group(argv[i], push_swap))
				return (0);
		}
		i++;
	}
	return (1);
}
