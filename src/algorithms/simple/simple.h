/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:47:53 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 22:07:27 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

# include "push_swap.h"

typedef struct s_move {
	t_node	*node_a;
	t_node	*target_b;
	int		cost_a;
	int		cost_b;
	int		total_cost;
}	t_move;

/* --- CONTROLLER --- */
void	greedy_sort(t_push_swap *push_swap);
//void	final_alignment(t_node **stack_a);
/* --- COST --- */
void	calculate_cost(t_node *stack_a, t_node *stack_b, t_move *move);
void	optimize_total_cost(t_move *move);
int		get_single_cost(int size, int index);
/* --- MOVES --- */
void	apply_moves(t_push_swap *push_swap, t_move *move);
void	rotate_both(t_push_swap *push_swap, t_move *move);
void	rotate_a(t_push_swap *push_swap, t_move *move);
void	rotate_b(t_push_swap *push_swap, t_move *move);
/* --- POSITION --- */
t_node	*get_target_node(t_node *stack_a, t_node *stack_b);
/* --- SORT_PUSH --- */
void	get_cheapest_move(t_push_swap *push_swap, t_move *best_move);
void	push_cheapest_to_b(t_push_swap *push_swap);
void	push_all_to_a(t_push_swap *push_swap);
void	rotate_stack_a(t_push_swap *push_swap, t_node *target);
/* --- SORT_THREE --- */
void	sort_three(t_push_swap *push_swap);


#endif