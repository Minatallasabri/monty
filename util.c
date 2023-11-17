#include "monty.h"

/**
 * parse_line - execute the desired operation
 * @args: The line feed form monty byte code
 * @stack: The current stack of operands
 * @line_num: The line number i.e operation number
 *
 * Return: the number of characters read
 *
 */
int parse_line(char *args, stack_t **stack, unsigned int line_num)
{
	char *opcode = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int idx = 0;

	opcode = strtok(args, DELIMITER);
	if (opcode == NULL)
		return (1);
	if (opcode && opcode[0] == '#')
		return (0);
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
		fprintf(stderr, " L%u: unknown instruction %s\n", line_num, opcode);
		free_all(*stack);
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
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(*stack);
		return;
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;

	if ((*stack) != NULL)
		(*stack)->prev = new;

	*stack = new;

}
/**
 * free_all - handle all file closing anf freeing and exit
 * @stk: The current stack of operands
 *
 */
void free_all(stack_t *stk)
{
	free_stack(stk);
	free(ops.line);
	fclose(ops.file);
	exit(EXIT_FAILURE);
}
