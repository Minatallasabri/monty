#include "monty.h"
/**
 * pint - prints top element of the stack
 * @stack: stack head
 * @line_num: Command number
 * Return: no return
*/
void pint(stack_t **stack, unsigned int line_num)
{
	
	if (*stack== NULL)
		{
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
			fclose(ops.file);
			free(ops.line);
			exit(EXIT_FAILURE);
        }
		printf("%d\n", (*stack)->n);
}
