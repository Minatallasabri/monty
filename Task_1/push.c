#include "monty.h"
/**
 * push - add node to the stack
 * @ope: operand content
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_num, char * ope)
{
	int n, i = 0, not_int = 0;

	if (ope)
	{
		if (ope[0] == '-')
			i++;
		for (; ope[i] != '\0'; i++)
			if (ope[i] > 57 || ope[i] < 48)
            {
                not_int = 1;
                break;
            }
		if (not_int == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	n = atoi(ope);
	add_node(stack, n);

}



