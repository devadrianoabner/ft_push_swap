#include "push_swap.h"
#include "common.h"


void	rotate_stack_a(t_push_swap *push_swap, t_node *target)
{
	t_move	move;
	int		size_a;
	int		index_a;

	size_a = stack_size(push_swap->stack_a);
	index_a = get_index(push_swap->stack_a, target);
	move.cost_a = get_single_cost(size_a, index_a);
	move.cost_b = 0;
	rotate_a(push_swap, &move);
}

void	push_all_to_a(t_push_swap *push_swap)
{
	t_node	*target_node;

	while (push_swap->stack_b)
	{
		target_node = get_target_for_b(push_swap->stack_a, push_swap->stack_b);
		rotate_stack_a(push_swap, target_node);
		pa(push_swap);
	}
}

void	final_alignment(t_push_swap *push_swap)
{
	t_node	*min_node;

	min_node = get_node(push_swap->stack_a, GET_MIN);
	if (!min_node)
		return ;
	rotate_stack_a(push_swap, min_node);
}