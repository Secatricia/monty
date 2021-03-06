#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

/** Library Utils */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Linked list functions */
size_t print_dlistint(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
size_t sizeLinkedList(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(stack_t *head);

/* Str functions */
char *str_trim(char *str);
char **splitArgs(char *str);

/* Stack functions */
void push_stack(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
void pop(stack_t **head, unsigned int number);
void swap(stack_t **head, unsigned int number);
void add(stack_t **head, unsigned int number);
void nop(stack_t **head, unsigned int number);
void sub(stack_t **head, unsigned int number);
void Div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void mod(stack_t **head, unsigned int number);

void (*getinst(int))(stack_t **, unsigned int);

int isNumber(char *str);

char **arguments;
FILE *file;
char *copy;

#endif
