/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:47:53 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/01 18:48:13 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

# include "push_swap.h"

typedef struct s_move {
	t_node	*node_a;
	t_node	*node_b;
	int		cost_a;
	int		cost_b;
	int		total_cost;
}	t_move;

void	greedy_sort(t_push_swap *push_swap);
void	calculate_cost(t_node *stack_a, t_node *stack_b);
t_node	*get_target_position(t_node *stack_a, t_node *stack_b);

#endif