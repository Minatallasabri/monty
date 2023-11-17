#include "monty.h"
/**
 * handle_push - add node to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void handle_push(stack_t **stack, unsigned int line_num)
{
	float floatValue = 0.0;
	int int_value, is_number = 1, i;

	if (!ops.int_value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_all();
		return;
	}
	if (ops.int_value[0] == '0')
	{
		add_node(stack, 0);
		return;
	}
	for (i = 0; ops.int_value[i] != '\0'; i++)
	{
		if (!isdigit(ops.int_value[i]) && ops.int_value[i] != '-')
		{
			if (ops.int_value[i] != '.')
				is_number = 0;
			break;
		}
	}

	floatValue = strtof(ops.int_value, NULL);
	int_value = (int)floatValue;
	if (floatValue != int_value || !is_number)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_all();
		return;
	}
	add_node(stack, int_value);
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
		free_stack();
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
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		free_all();
		return;
	}

	ops.stk = *stack;

	*stack = ops.stk->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ops.stk);
	ops.stk = *stack;
}
/**
 * swap - Swaps the top 2 elements of the stack
 * @stack: stack head
 * @line_num: The command number
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int stack_len = 0, tmp_num;
	ops.stk = *stack;


	while (ops.stk)
	{
		stack_len++;
		ops.stk = ops.stk->next;
	}
	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		ops.stk = *stack;
		free_all();
	}
	ops.stk = *stack;

	tmp_num = (*stack)->n;
	ops.stk->n = ops.stk->next->n;
	ops.stk->next->n = tmp_num;
}
