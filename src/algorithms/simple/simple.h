/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:47:53 by adrianda          #+#    #+#             */
/*   Updated: 2026/08/08 15:19:44 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

#include "../common/common.h"

void	greedy_sort(t_push_swap *push_swap);
void	get_cheapest_move(t_push_swap *push_swap, t_move *best_move);
void	push_cheapest_to_b(t_push_swap *push_swap);
void	simple_sort(t_push_swap *push_swap);

#endif