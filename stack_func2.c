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
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		free(arguments);
		fclose(file);
		free(copy);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;

	while (ptr->next)
		ptr = ptr->next;
	temp = ptr->n;
	ptr->n = ptr->prev->n;
	ptr->prev->n = temp;
}
