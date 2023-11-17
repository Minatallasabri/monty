#include "monty.h"
/**
 * queue - prints the top
 * @head: stack head
 * @line_num: line_number
 * Return: no return
*/
void queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	ops.int_value = "";
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *tmp_num;

	tmp_num = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tmp_num)
	{
		while (tmp_num->next)
			tmp_num = tmp_num->next;
	}
	if (!tmp_num)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp_num->next = new_node;
		new_node->prev = tmp_num;
	}
}
