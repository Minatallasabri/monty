#include "monty.h"
/**
 * _div - divides the top two elements of the stack.
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
void _div(stack_t **head, unsigned int line_num)
{
	int len = 0, tmp;

	ops.stk = *head;
	while (ops.stk)
	{
		ops.stk = ops.stk->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		ops.stk = *head;
		free_all();
	}
	ops.stk = *head;
	if (ops.stk->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		free_all();
	}
	tmp = ops.stk->next->n / ops.stk->n;
	ops.stk->next->n = tmp;
	pop(head, line_num);
}
