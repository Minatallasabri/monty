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

/**
 * pall - prints the stack
 * @stack: stack head
 * @line_num: not used
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void) line_num;



	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - prints top element of the stack
 * @stack: stack head
 * @line_num: Command number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_num)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		fclose(ops.file);
		free(ops.line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
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
