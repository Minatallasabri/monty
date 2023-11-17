#include "monty.h"
void parse_line(char *args, stack_t **stack, unsigned int line_num);
/**
 * parse_line - execute the desired operation
 * @args: The line feed form monty byte code
 * @stack: The current stack of operands
 * @line_num: The line number i.e operation number
 *
 * Return: the number of characters read
 *
 */
void parse_line(char *args, stack_t **stack, unsigned int line_num)
{
	char *opcode = NULL;
	unsigned int idx = 0, flag = 0;
	instruction_t opcodes[] = {
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"nop", nop},
		{"swap", swap},
		{"pchar", pchar},
		{"pstr", pstr},
		{"mul", mul},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	opcode = strtok(args, DELIMITER);
	if (opcode == NULL)
		return;
	if (opcode && opcode[0] == '#')
		return;
	ops.int_value = strtok(NULL, DELIMITER);
	if (strcmp(opcode, "push") == 0)
	{
		handle_push(stack, line_num);
		return;
	}
	while (opcodes[idx].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[idx].opcode) == 0)
		{
			opcodes[idx].func(stack, line_num);
			return;
		}
		idx++;
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		free_all();
	}
}


/**
 * free_stack - Free the stack
 *
 */
void free_stack(void)
{
	stack_t *head = ops.stk;

	while (ops.stk)
	{
		head = ops.stk->next;
		free(ops.stk);
		ops.stk = head;
	}
}
/**
 * add_node - adds a new node at the beginning
 * of the stack
 *
 * @stack: head of the list
 * @n: value of the element
 */
void add_node(stack_t **stack, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		return;
	}

	node->n = n;
	node->prev = NULL;
	node->next = *stack;

	if (*stack)
		(*stack)->prev = node;

	*stack = node;
	ops.stk = node;
}
/**
 * free_all - handle all file closing anf freeing and exit
 *
 */
void free_all(void)
{
	free_stack();
	free(ops.line);
	fclose(ops.file);
	exit(EXIT_FAILURE);
}

#include "monty.h"

/**
 * read_line - Reads lines from a file
 * @file: Pointer to the file to read from
 *
 * This function reads lines from the provided file and performs
 * the necessary operations on each line.
 */
void read_line(FILE *file)
{
	unsigned int num_lines = 1;
	size_t n = 0;
	char *line = NULL;
	stack_t *stack = NULL;

	while (getline(&line, &n, file) != -1)
	{
		ops.line = line;
		parse_line(line, &stack, num_lines);
		num_lines++;
	}
	free(line);
}
