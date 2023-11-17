#include "monty.h"
/**
 * pchar - add node to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	ops.stk = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't char, stack empty\n", line_num);
		free_all();
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't char, value out of range\n", line_num);
		free_all();
	}
	printf("%c\n", ops.stk->n);
}

/**
 * pstr - add node to the stack
 * @stack: stack head
 * @line_num: not used
 * Return: no return
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void) line_num;

	while (tmp != NULL)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate the stack to the left
 * @stack: stack head
 * @line_num: not used
 * Return: no return
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	int tmp_num;
	stack_t *tmp = ops.stk;
	(void) line_num;

	ops.stk = *stack;
	if (ops.stk == NULL || ops.stk->next == NULL)/*empty or one element stack*/
		return;
	tmp_num = ops.stk->n;
	while (ops.stk != NULL && ops.stk->next != NULL)
	{
		ops.stk->n = ops.stk->next->n;
		ops.stk = ops.stk->next;
	}
	ops.stk = tmp;
	ops.stk->n = tmp_num;
}
/**
 * rotr - Rotate the stack to the right
 * @stack: stack head
 * @line_num: not used
 * Return: no return
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *prev;
	(void) line_num;
	if (tmp == NULL || tmp->next == NULL)/*empty or one element stack*/
		return;

	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	prev = tmp->prev;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack) = tmp;
	prev->next = NULL;
}
