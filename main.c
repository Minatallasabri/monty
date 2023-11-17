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
	FILE *file;
	stack_t *stack = NULL;

	(void)ops;
	/*check If the user does not give any file*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /*open the file*/
	if (!file || !argv[1]) /*check If, it’s not possible to open the file*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ops.file = file;
	read_line(file);/*start reading*/
	free_stack(stack);
	fclose(file);
	return (0);
}

