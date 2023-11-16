#include "monty.h"
/**
 * push - add node to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_num)
{
	int n, i = 0, not_int = 0;

	if (ops.int_value)
	{
		if (ops.int_value[0] == '-')
			i++;
		for (; ops.int_value[i] != '\0'; i++)
			if (ops.int_value[i] > 57 || ops.int_value[i] < 48)
			{
				not_int = 1;
				break;
			}
		if (not_int == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(ops.file);
			free(ops.line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(ops.file);
		free(ops.line);
		exit(EXIT_FAILURE);
	}
	n = atoi(ops.int_value);
	add_node(stack, n);
}
