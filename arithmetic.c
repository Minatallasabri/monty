#include "monty.h"

/**
 * mul - Multiply the top 2 elements of the stack
 * @stack: stack head
 * @line_num: The command number
 * Return: no return
 */
void mul(stack_t **stack, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(ops.file);
		free_stack(*stack);
		free(ops.line);
		exit(EXIT_FAILURE);
	}
	tmp_num = (*stack)->n;
	(*stack)->next->n = tmp_num * (*stack)->next->n;
	pop(stack, line_num);
	free(tmp);
}
#include "monty.h"

/**
 * mod - Compute the reminder of the division of top 2 elements of the stack
 * @stack: stack head
 * @line_num: The command number
 * Return: no return
 */
void mod(stack_t **stack, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		fclose(ops.file);
		free_stack(*stack);
		free(ops.line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(ops.file);
		free_stack(*stack);
		free(ops.line);
		exit(EXIT_FAILURE);
	}
	tmp_num = (*stack)->n;
	(*stack)->next->n =  (*stack)->next->n % tmp_num;
	pop(stack, line_num);
	free(tmp);
}
