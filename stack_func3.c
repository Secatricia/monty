#include "monty.h"

/**
 * Div - divide the two top values of the stack and delete the top one
 * @head: pointer of pointer struct stack_t
 * @number: int
 *
 * Return: Void
 */
void Div(stack_t **head, unsigned int number)
{
	int n;
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", number);
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

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		free(arguments);
		fclose(file);
		free(copy);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	ptr->prev->n = ptr->prev->n / ptr->n;
	delete_dnodeint_at_index(head, n - 1);
}

/**
 * mul - multiply the two top values of the stack and delete the top one
 * @head: pointer of pointer struct stack_t
 * @number: int
 *
 * Return: Void
 */

void mul(stack_t **head, unsigned int number)
{
	int n;
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", number);
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

	ptr->prev->n = ptr->prev->n * ptr->n;
	delete_dnodeint_at_index(head, n - 1);
}

/**
 * mod - modulus the two top values of the stack and delete the top one
 * @head: pointer of pointer struct stack_t
 * @number: int
 *
 * Return: Void
 */
void mod(stack_t **head, unsigned int number)
{
	int n;
	stack_t *ptr;

	if (sizeLinkedList(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
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

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		free(arguments);
		fclose(file);
		free(copy);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	ptr->prev->n = ptr->prev->n % ptr->n;
	delete_dnodeint_at_index(head, n - 1);
}

/**
 * pchar - Prints the char at the top of the stack
 * @head: pointer of pointer
 * @number: int
 *
 * Return: Void
 */

void pchar(stack_t **head, unsigned int number)
{
	stack_t *ptr;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;

	while (ptr->next)
		ptr = ptr->next;

	if (ptr->n <= 0 || ptr->n >= 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", ptr->n);
}
