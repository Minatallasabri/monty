#include "monty.h"

/**
* add - function that adds the top two elements of the stack
* @head: double pointer head to the stack
* @line_num: line number
*
* Return: nothing
*/
void add(stack_t **head, unsigned int line_num)
{
	int tmp_num = 0;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		ops.stk = *head;
		free_all();
		return;
	}
	ops.stk = *head;
	tmp_num = ops.stk->n + ops.stk->next->n;
	ops.stk->next->n = tmp_num;
	pop(head, line_num);
}
