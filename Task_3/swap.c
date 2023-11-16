#include "monty.h"
/**
 * swap - Swaps the top 2 elements of the stack
 * @stack: stack head
 * @line_num: The command number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp = *stack;
    int stack_len = 0, tmp_num;

    while (tmp)
    {
        stack_len++;
        tmp = tmp->next;
    }
	if (stack_len < 2)
		{
            fprintf(stderr, "L%d: can't swap, stack too short,\n", line_num);
            fclose(ops.file);
			free(ops.line);
			exit(EXIT_FAILURE);
        }
        tmp_num = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = tmp_num;
        free(tmp);
}
