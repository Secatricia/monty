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
	if (arguments[1] != NULL && isNumber(arguments[1]) == 0)
		add_dnodeint_end(head, atoi(arguments[1]));
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		free_dlistint(*head);
		free(arguments);
		exit(EXIT_FAILURE);
	}
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

/**
 * pint - Print value at top of the stack
 * @head: pointer of pointer
 * @number: int
 *
 * Return: Void
 */

void pint(stack_t **head, unsigned int number)
{
	stack_t *i = *head;

	if (i == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}

	while (i->next)
	{
		i = i->next;
	}
	printf("%d\n", i->n);
}
