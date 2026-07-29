/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:30:52 by rafcrist          #+#    #+#             */
/*   Updated: 2026/07/29 20:27:15 by rafcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_flags(t_flag *flags)
{
	flags[0].name = "--simple";
	flags[0].code = FLAG_SIMPLE;
	flags[1].name = "--medium";
	flags[1].code = FLAG_MEDIUM;
	flags[2].name = "--complex";
	flags[2].code = FLAG_COMPLEX;
	flags[3].name = "--adaptive";
	flags[3].code = FLAG_ADAPTIVE;
	flags[4].name = "--bench";
	flags[4].code = FLAG_BENCH;
	flags[5].name = NULL;
	flags[5].code = FLAG_NONE;
}

t_flag_id	get_flag_code(char *str)
{
	t_flag		flags[6];
	int			i;

	init_flags(flags);
	i = 0;
	while (flags[i].name != NULL)
	{
		if (ft_strlen(str) == ft_strlen(flags[i].name)
			&& ft_strncmp(str, flags[i].name, ft_strlen(str)) == 0)
			return (flags[i].code);
		i++;
	}
	return (FLAG_NONE);
}
