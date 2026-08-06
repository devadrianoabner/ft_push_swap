/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:08:00 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 21:15:44 by adrianda         ###   ########.fr       */
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

typedef enum e_flag_id
{
	FLAG_NONE,
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE,
	FLAG_BENCH
}	t_flag_id;

typedef struct s_flag
{
	char		*name;
	t_flag_id	code;
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
	t_node		*stack_a;
	t_node		*stack_b;
	int			op_counts[OP_TYPES_TOTAL];
	int			bench;
	t_flag_id	strategy;
}	t_push_swap;

/* --- PARSER --- */
int				is_valid(char *str);
int				has_duplicate(t_push_swap *push_swap, int temp_num);
int				is_flag(char *str);
int				is_int_range(char *str);
t_flag_id		get_flag_code(char *str);
int				parse_arguments(int argc, char **argv, t_push_swap *push_swap);
int				handle_error(t_push_swap *push_swap);
/* --- INITIALIZATION --- */
void			init_push_swap(t_push_swap *push_swap);
/* --- CLEAN --- */
void			cleanup_push_swap(t_push_swap *push_swap);
void			free_stack(t_node *stack);
/* --- PUSH --- */
void			pa(t_push_swap *push_swap);
void			pb(t_push_swap *push_swap);
/* --- ROTATE REVERSE --- */
void			rra(t_push_swap *push_swap);
void			rrb(t_push_swap *push_swap);
void			rrr(t_push_swap *push_swap);
/* --- ROTATE --- */
void			ra(t_push_swap *push_swap);
void			rb(t_push_swap *push_swap);
void			rr(t_push_swap *push_swap);
/* --- SWAP --- */
void			sa(t_push_swap *push_swap);
void			sb(t_push_swap *push_swap);
void			ss(t_push_swap *push_swap);
/* --- STACK --- */
int				stack_size(t_node *stack);
int				stack_a_add_back(t_push_swap *push_swap, int value);
int				is_sorted(t_node *stack);
t_node			*find_tail(t_node *stack);
int				get_index(t_node *stack, t_node *node);
int				get_rank(t_push_swap *push_swap, t_node *node);
/* --- NODE --- */
int				node_compare(t_node *src, t_node *dest);
t_node			*get_node(t_node *stack, int type);
t_node			*second_last(t_node *stack);

/* --- METRICS --- */
void			count_op(t_push_swap *push_swap, t_op op);
/* --- SIMPLE CONTROLLER --- */
void			simple_sort(t_push_swap *push_swap);
/* --- COMPLEX CONTROLLER --- */
void	complex_sort(t_push_swap *push_swap);
/* --- TEMPORÁRIO: ambiente de testes --- */
t_push_swap		*build_dummy_stack(int *values_a, int n_a,
					int *values_b, int n_b);
void			print_stack(t_node *stack_a);
#endif