#include "monty.h"
/**
 * parse_line - execute the desired operation
 * @args: The line feed form monty byte code
 * @stack: The current stack of operands
 * @line_num: The line number i.e operation number
 * @file: the file to read instruction from
 *
 * Return: the number of characters read
 *
 */
int parse_line(char *args, stack_t **stack, unsigned int line_num, FILE *file)
{
	char *opcode = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	int idx = 0;

	opcode = strtok(args, DELIMITER);
	ops.int_value = strtok(NULL, DELIMITER);
	while (opcodes[idx].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[idx].opcode) == 0)
		{
			opcodes[idx].func(stack, line_num);
			return (0);
		}
		idx++;
	}
	if (opcode && opcodes[idx].opcode == NULL)
	{
		fprintf(stderr, " L%u: unknown instruction %s\n\n", line_num, opcode);
		fclose(file);
		free(args);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1); /*error form opcode*/
}


/**
 * free_stack - Free the stack
 * @stack: The stack to be freed
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *head = stack;

	while (stack)
	{
		head = stack->next;
		free(stack);
		stack = head;
	}
}
/**
 * add_node - adds a new node at the beginning
 * of the stack
 *
 * @stack: head of the list
 * @n: value of the element
 */
void add_node(stack_t **stack, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;
	new->n = n;
	new->prev = NULL;


	if ((*stack) != NULL)
	{
		while ((*stack)->prev != NULL)
			*stack = (*stack)->prev;
	}

	new->next = *stack;

	if ((*stack) != NULL)
		(*stack)->prev = new;

	*stack = new;

}
