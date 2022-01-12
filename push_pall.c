#include "monty.h"

/**
 * push_stack - Push an element to the stack
 * @head: pointer of pointer to struct stack_t
 * @number: unsigned int
 *
 * Return: Void
 */

void push_stack(stack_t **head, unsigned int number)
{
	if (!*head && number)
		printf("%d\n",VALUE);
}

/**
 * pall - Prints all values on the stack, starting from top
 * @head: pointer of pointer to struct stack_t
 * @number: unsigned int
 *
 * Return: Void
 */

void pall(stack_t **head, unsigned int number __attribute__((unused)))
{
	print_dlistint(*head);
}
