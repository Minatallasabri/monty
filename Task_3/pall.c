#include "monty.h"
/**
 * pall - prints the stack
 * @stack: stack head
 * @num_line: not used
 * Return: no return
*/
void pall(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp = *stack;
    (void) line_num;

	

	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
