#include "monty.h"
/**
  *sub- sustration
  *@head: stack head
  *@line_num: line_number
  *Return: no return
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *tmp_num;
	int nod, nodes;

	tmp_num = *head;
	for (nodes = 0; tmp_num != NULL; nodes++)
		tmp_num = tmp_num->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(ops.file);
		free(ops.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp_num = *head;
	nod = tmp_num->next->n - tmp_num->n;
	tmp_num->next->n = nod;
	*head = tmp_num->next;
	free(tmp_num);
}
