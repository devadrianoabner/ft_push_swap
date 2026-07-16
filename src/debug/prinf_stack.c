#include "push_swap.h"

void	print_stack(t_node *stack_a)
{
	if (!stack_a)
	{
		printf("Nenhuma pilha foi formada");
		return ;
	}
	while (stack_a != NULL)
	{
		printf("Indice: %d | Valor %d\n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
	}
}