#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DELIMITER " \n\t"
#define BUFFER_SIZE 15000

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct operation_s - Information needed to be carried bettween files
 * @int_value: The inteager in the line
 * @line: The line red from file
 * @file: The file providing the commands
 * @stk: The stack head
 *
 * Description: info needed
 * for stack, queues, LIFO, FIFO
 */
typedef struct operation_s
{
	char  *int_value;
	char *line;
	FILE *file;
	stack_t *stk;
} operation_t;

extern operation_t ops;

/*manipulate_stack_1_module.c*/
void handle_push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **head, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);

/*manipulate_stack_1_module_2.c*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*arithmetic.c*/
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/*util.c*/
void parse_line(char *, stack_t **, unsigned int);
void free_stack(void);
void add_node(stack_t **head, int n);
void free_all(void);
void read_line(FILE *file);
#endif

