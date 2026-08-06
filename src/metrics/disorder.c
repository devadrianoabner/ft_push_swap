#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	t_node  *current;
	t_node  *compare;
	int     inversions;
	int     total_pairs;

	if (stack == NULL || stack->next == NULL)
		return (0.0);
	inversions = 0;
	total_pairs = 0;
	current = stack;
	while (current->next != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			total_pairs++;
			if (current->value > compare->value)
				inversions++;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((double)inversions / total_pairs);
}