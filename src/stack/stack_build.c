#include "push_swap.h"

static t_node	*create_node(int value)
{
    t_node  *new_node;

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
	{
    	push_swap->stack_a = new_node;
    	push_swap->tail_a = new_node;
	}
	else
	{
		push_swap->tail_a->next = new_node;
		push_swap->tail_a = new_node;
	}
	return (1);
}

/*
index
1 0 0
3 1 2
5 2 4
4 3 3
6 4 5
2 5 1
9 6 7
851819 7 6*/