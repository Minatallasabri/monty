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
	stack_t *h;
	int length = 0, tmp_num;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(ops.file);
		free(ops.line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp_num = h->n + h->next->n;
	h->next->n = tmp_num;
	*head = h->next;
	free(h);
}

