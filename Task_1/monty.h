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
 * stack_s - doubly linked list representation of a stack (or queue)
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
 * instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*func)(stack_t **stack, unsigned int line_number, char *operand);
} instruction_t;



void push(stack_t **, unsigned int, char *);
void pall(stack_t **, unsigned int, char *);
int parse_line(char *, stack_t **, unsigned int , FILE *);
void free_stack(stack_t *);
void add_node(stack_t **head, int n);

#endif