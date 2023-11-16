#include "monty.h"
/**
 * pop - prints top element of the stack
 * @stack: stack head
 * @line_num: The command number
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp = *stack;
	
	if (*stack == NULL)
		{
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
            fclose(ops.file);
			free(ops.line);
			exit(EXIT_FAILURE);
        }
        *stack = tmp->next;
        free(tmp);
}
