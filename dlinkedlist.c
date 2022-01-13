#include "monty.h"

/**
 * print_dlistint - Prints all elements of a stack_t list.
 * @h: struc stack_t
 *
 * Return: Number of nodes
 */

size_t print_dlistint(const stack_t *h)
{
	int nbNodes = 0;

	if (h)
	{
		while (h->next)
		{
			h = h->next;
			nbNodes++;
		}
		while (h)
		{
			printf("%d\n", h->n);
			h = h->prev;
		}
	}
	return (nbNodes);
}

/**
 * add_dnodeint - Adds a new node at the beginning of a stack_t list.
 * @head: pointer of pointer to struct stack_t
 * @n: integer
 *
 * Return: Adress of the new element or NULL if it failed
 *
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->prev = NULL;
	new->n = n;
	new->next = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: pointer of pointer to struct dlistint_t struct
 * @n: integer
 *
 * Return: Adress of new element or NULL if it failed.
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *ptr = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	return (new);
}

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: pointer of struct dlistint_t list
 *
 * Return: Void
 */

void free_dlistint(stack_t *head)
{
	stack_t *ptr = head;

	if (head)
	{
		while (head)
		{
			ptr = head;
			head = head->next;
			free(ptr);
		}
	}
}
