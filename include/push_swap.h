/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:08:00 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/16 19:34:49 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // retirar depois
# include "libft.h"

typedef struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;

typedef struct	s_flag
{
	char	*name;
	int		code;
} t_flag;

typedef struct	s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	op_sa;
	int	total_ops;
} t_ps;

int	is_valid(char *str);
int	has_duplicate(t_ps *push_swap, int temp_num);
int	is_flag(char *str);
int	is_int_range(char *str);

#endif
