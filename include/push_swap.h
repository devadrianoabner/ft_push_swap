/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:08:00 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/30 20:05:07 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // retirar depois
# include "libft.h"

# define GET_MIN 0
# define GET_MAX 1

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_flag
{
	char	*name;
	int		code;
}	t_flag;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_TYPES_TOTAL
}	t_op;

typedef struct s_push_swap
{
	t_node	*stack_a;
	t_node	*tail_a;
	t_node	*stack_b;
	t_node	*tail_b;
	int		op_counts[OP_TYPES_TOTAL];
}	t_push_swap;

int				is_valid(char *str);
int				has_duplicate(t_push_swap *push_swap, int temp_num);
// push
void			pa(t_push_swap *push_swap);
void			pb(t_push_swap *push_swap);
// rotate reverse
void			rra(t_push_swap *push_swap);
void			rrb(t_push_swap *push_swap);
void			rrr(t_push_swap *push_swap);
// rotate
void			ra(t_push_swap *push_swap);
void			rb(t_push_swap *push_swap);
void			rr(t_push_swap *push_swap);
// swap
void			sa(t_push_swap *push_swap);
void			sb(t_push_swap *push_swap);
void			ss(t_push_swap *push_swap);
// stack
int				stack_size(t_node *stack);
int				is_empty(t_node *stack);
t_node			*second_last(t_node *stack);
int				stack_a_add_back(t_push_swap *push_swap, int value);
int				is_sorted(t_node *stack);
// node
int				node_compare(t_node *src, t_node *dest);
t_node			*get_node(t_node *stack, int type);
// metrics
void			count_op(t_push_swap *push_swap, t_op op);
// temporário, só para ambiente de testes
t_push_swap		*build_dummy_stack(int *values_a, int n_a,
					int *values_b, int n_b);
void			print_stack(t_node *stack_a);
void			free_stack(t_node *stack);
// parser
int	is_valid(char *str);
int	has_duplicate(t_push_swap *push_swap, int temp_num);
int	is_flag(char *str);
int	is_int_range(char *str);


#endif