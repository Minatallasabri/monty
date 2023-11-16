#include "monty.h"
/**
 * pint - prints top element of the stack
 * @stack: stack head
 * @ope: not used
 * @num_line: not used
 * Return: no return
*/
void pint(stack_t **stack, unsigned int line_num, char *ope)
{
    (void) ope;
	
	if (*stack== NULL)
		{
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
			exit(EXIT_FAILURE);
        }
		printf("%d\n", (*stack)->n);
}
