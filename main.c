#include "monty.h"
operation_t ops = {NULL, NULL, NULL};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file; /*file pointer*/
	size_t size = 0;
	int read_line = 1;
	stack_t *stack = NULL; /*pointer to the stack*/
	unsigned int counter = 0;

	if (argc != 2) /*input not monty file*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /*read  monty file containg input and opcodes*/
	if (!file || !argv[1])
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ops.file = file;
	while (read_line > 0)
	{
		read_line = getline(&content, &size, file);
		ops.line = content;
		counter++;
		if (read_line > 0)
		{
			parse_line(content, &stack, counter);
		}
	}
	free(content);
	free_stack(stack);
	fclose(file);
	return (0);
}
