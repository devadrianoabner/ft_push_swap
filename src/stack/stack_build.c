#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	stack_a_add_back(t_push_swap *push_swap, int value)
{
	t_node	*new_node;

	if (push_swap == NULL)
		return (0);
	new_node = create_node(value);
	if (new_node == NULL)
		return (0);
	if (push_swap->stack_a == NULL)
		push_swap->stack_a = new_node;
	return (1);
}
