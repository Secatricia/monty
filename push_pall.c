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
	add_dnodeint_end(head, number);
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
	if (*head)
	{
		print_dlistint(*head);
	}
}

void pint(stack_t **head, unsigned int number __attribute__((unused)))
{
	if (*head)
	{
		while ((*head)->next)
		{
			(*head) = (*head)->next;
		}
		printf("%d\n", (*head)->n);
	}
}
