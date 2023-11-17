#include "monty.h"
/**
  *sub- sustration
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
void sub(stack_t **head, unsigned int line_num)
{
	int nod, nodes;

	ops.stk = *head;
	for (nodes = 0; ops.stk != NULL; nodes++)
		ops.stk = ops.stk->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		ops.stk = *head;
		free_all();
	}
	ops.stk = *head;
	nod = ops.stk->next->n - ops.stk->n;
	ops.stk->next->n = nod;
	pop(head, line_num);
}
