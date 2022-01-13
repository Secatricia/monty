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

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: pointer of pointer to struct dlistint_t
 * @index: index of the node that should be deleted
 *
 * Return: 1 on success, -1 if it failed.
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp, *last, *temp2;
	unsigned int i = 0;

	if (!head)
		return (-1);
	if (*head == NULL || index > sizeLinkedList(*head))
		return (-1);
	temp = last = *head;
	if (index == 0)
	{
		if ((*head)->next)
		{
			(*head)->next->prev = NULL;
			*head = (*head)->next;
			free(temp);
			return (1);
		}
		free(temp), *head = NULL;
		return (1);
	}
	while (i < index)
		temp = temp->next, i++;
	i = 0;
	while (i < (index - 1))
	{
		last = last->next;
		i++;
	}
	if (!temp->next)
	{
		last->next = NULL;
		free(temp);
		return (1);
	}
	temp2 = temp->next;
	last->next = temp->next;
	temp2->prev = temp->prev;
	free(temp);
	return (1);
}

/**
 * sizeLinkedList - Return the size of linked list
 * @h: pointer of struct dlistint_t
 *
 * Return: number of nodes
 */

size_t sizeLinkedList(const stack_t *h)
{
	unsigned int n = 0;

	if (h)
	{
		while (h)
		{
			n++;
			h = h->next;
		}
	}
	return (n);
}
