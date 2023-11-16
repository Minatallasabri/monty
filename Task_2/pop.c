#include "monty.h"
/**
 * pint - prints top element of the stack
 * @stack: stack head
 * @ope: not used
 * @line_num: The command number
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_num, char *ope)
{
    stack_t *tmp = *stack;
    (void) ope;
	
	if (*stack== NULL)
		{
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
			exit(EXIT_FAILURE);
        }
        *stack = tmp->next;
        free(tmp);
}
