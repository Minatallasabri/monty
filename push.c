#include "monty.h"
/**
 * push - add node to the stack
 * @ope: operand content
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_num, char *ope)
{
	int num, idx = 0, not_int = 0;

	if (ope)
	{
		if (ope[0] == '-')
			idx++;
		for (; ope[idx] != '\0'; idx++)
			if (ope[idx] > 57 || ope[idx] < 48)
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
	num = atoi(ope);
	add_node(stack, num);

}
