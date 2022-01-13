#include "monty.h"

/**
 * swap - Swap the 2 elements at the top of the stack
 * @head: pointer of pointer struct
 * @number: int
 *
 * Return: Void
 */

void swap(stack_t **head, unsigned int number)
{
	int temp;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while ((*head)->next)
	{
		*head = (*head)->next;
	}
	temp = (*head)->n;
	(*head)->n = (*head)->prev->n;
	(*head)->prev->n = temp;
}
