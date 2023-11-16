#include "monty.h"
/**
 * pall - prints the stack
 * @stack: stack head
 * @ope: not used
 * @line_num: not used
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_num, char *ope)
{
	stack_t *tmp = *stack;
	(void) line_num;
	(void) ope;


	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

