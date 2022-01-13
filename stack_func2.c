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

/**
 * add - Add the two top values of the stack and delete the top one
 * @head: pointer of pointer struct stack_t
 * @number: int
 *
 * Return: Void
 */

void add(stack_t **head, unsigned int number)
{
	int n;
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		free(arguments);
		fclose(file);
		free(copy);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	n = sizeLinkedList(*head);

	while (ptr->next)
		ptr = ptr->next;

	ptr->prev->n = ptr->n + ptr->prev->n;
	delete_dnodeint_at_index(head, n - 1);
}

/**
 * nop - sert a rien
 * @head: pointer of pointer
 * @number: int
 *
 * Return: Void
 */

void nop(stack_t **head, unsigned int number)
{
	number = number;
	*head = *head;
}

/**
 * sub - sub the two top values of the stack and delete the top one
 * @head: pointer of pointer struct stack_t
 * @number: int
 *
 * Return: Void
 */
void sub(stack_t **head, unsigned int number)
{
	int n;
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", number);
		free(arguments);
		fclose(file);
		free(copy);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	n = sizeLinkedList(*head);

	while (ptr->next)
		ptr = ptr->next;

	ptr->prev->n = ptr->prev->n - ptr->n;
	delete_dnodeint_at_index(head, n - 1);
}
